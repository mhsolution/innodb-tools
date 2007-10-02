#!/usr/bin/env perl

use strict;
use DBI;
use Data::Dumper;

my $db_name = "scm_prod";
my $db_host = "127.0.0.1";
my $db_port = 3333;
my $db_user = "root";
my $db_pass = "";

my $dsn = "DBI:mysql:database=$db_name;host=$db_host;port=$db_port";
my $dbh = DBI->connect($dsn, $db_user, $db_pass);

die "Can't connect!" unless $dbh;

my $sth = $dbh->prepare("SHOW TABLES");
$sth->execute;

print("#ifndef table_defs_h\n#define table_defs_h\n\n");
print("// Table definitions\ntable_def_t table_definitions[] = {\n");


while (my $row = $sth->fetchrow_arrayref) {
	my $table = $row->[0];

	# Get fields list for table
	my @fields = ();
	my $tbl_sth = $dbh->prepare("SHOW FIELDS FROM $table");
	$tbl_sth->execute;
	while (my $field = $tbl_sth->fetchrow_hashref) { push @fields, $field }

	# Get primary key fields
	my @pk_fields = ();
	$tbl_sth = $dbh->prepare("show indexes from $table");
	$tbl_sth->execute;
	while (my $field = $tbl_sth->fetchrow_hashref) { 
		push @pk_fields, $field if ($field->{Key_name} eq 'PRIMARY');
	}

	# If no primary keys defined, check unique keys and use first one as primary
	if (scalar(@pk_fields) == 0) {
		$tbl_sth = $dbh->prepare("show indexes from $table");
		$tbl_sth->execute;
		my $pk_name = undef;
		while (my $field = $tbl_sth->fetchrow_hashref) { 
			next unless ($field->{Non_unique} == 0);
			$pk_name = $field->{Key_name} unless ($pk_name);
			last if ($field->{Key_name} ne $pk_name);
			push @pk_fields, $field;
		}
	}

	DumpTableDef($table, \@fields, \@pk_fields);
}

print("};\n\nint table_definitions_cnt = sizeof(table_definitions) / sizeof(table_def_t);\n\n\n");
print("\n#endif\n");

exit(0);

#------------------------------------------------------------------
sub DumpTableDef($$$) {
	my $table = shift;
	my $fields = shift;
	my $pk_fields = shift;

	print("\t{\n\t\t\"$table\",\n\t\t{\n");
	
	# Dump all PK fields
	foreach my $pk_field (@$pk_fields) {
		DumpField($table, FindFieldByName($fields, $pk_field->{Column_name}));
	}
	
	# Dump system PK if no PK fields found
	if (scalar(@$pk_fields) == 0) {
		DumpFieldLow(Name => 'DB_ROW_ID', Type => 'FT_INTERNAL', Len => 6, Null => 0);
	}
	
	# Dump 2 more sys fields
	DumpFieldLow(Name => 'DB_TRX_ID', Type => 'FT_INTERNAL', Len => 6, Null => 0);
	DumpFieldLow(Name => 'DB_ROLL_PTR', Type => 'FT_INTERNAL', Len => 7, Null => 0);
	
	# Dump the rest of the fields
	foreach my $field (@$fields) {
		DumpField($table, $field) unless $field->{Key} eq 'PRI';
	}

	print("\t\t\t{ \"\", 0 }\n");
	print("\t\t}\n\t},\n");
}

#------------------------------------------------------------------
sub FindFieldByName($$) {
	my $fields = shift;
	my $name = shift;

	foreach my $field (@$fields) {
		return $field if $field->{Field} eq $name;
	}

	return undef;
}

#------------------------------------------------------------------
sub DumpFieldLow {
	my %info = @_;
	unless(defined($info{LenMin})) {
		$info{LenMin} = $info{LenMax} = $info{Len};
	}
	printf("\t\t\t{ \"%s\", %s, %d, %d },\n", $info{Name}, $info{Type}, (!$info{Null})*$info{LenMin}, $info{LenMax});
}

#------------------------------------------------------------------
sub DumpField($$) {
	my $table = shift;
	my $field = shift;
	
	my %info;
	$info{Null} = ($field->{Null} eq 'YES');
	$info{Name} = $field->{Field};
	
	my $type_info = ParseFieldType($field->{Type});
	if ($type_info->{type} eq 'FT_INT' && IsFieldUnsigned($table, $field->{Field})) {
		$type_info->{type} = 'FT_UINT';
	}
	
	$info{Type} = $type_info->{type};
	$info{LenMin} = $type_info->{len_min};
	$info{LenMax} = $type_info->{len_max};

	DumpFieldLow(%info);
}

#------------------------------------------------------------------
sub IsFieldUnsigned($$) {
	my ($table, $field) = @_;
	my $sth = $dbh->prepare("SHOW CREATE TABLE $table");
	$sth->execute;
	my $row = $sth->fetchrow_arrayref;
	return ($row->[1] =~ /$field[^,]*unsigned/i);
}

#------------------------------------------------------------------
sub ParseFieldType($) {
	my $type = shift;
	
	if ($type =~ /DATETIME/i) {
		return { type => 'FT_DATETIME', len_min => 8, len_max => 8 };
	}

	if ($type =~ /TIMESTAMP/i) {
		return { type => 'FT_UINT', len_min => 4, len_max => 4 };
	}

	if ($type =~ /DATE/i) {
		return { type => 'FT_DATE', len_min => 8, len_max => 8 };
	}

	if ($type =~ /^BIGINT/i) {
		return { type => 'FT_INT', len_min => 8, len_max => 8 };
	}

	if ($type =~ /^INT/i) {
		return { type => 'FT_INT', len_min => 4, len_max => 4 };
	}

	if ($type =~ /^SMALLINT/i) {
		return { type => 'FT_INT', len_min => 2, len_max => 2 };
	}

	if ($type =~ /^TINYINT/i) {
		return { type => 'FT_INT', len_min => 1, len_max => 1 };
	}

	if ($type =~ /(.*)CHAR\((\d+)\)/i) {
		return { type => 'FT_CHAR', len_min => ($1 ne '' ? 0 : $2), len_max => $2 };
	}

	if ($type =~ /^TEXT/i) {
		return { type => 'FT_CHAR', len_min => 0, len_max => 65535 };
	}

	if ($type =~ /^FLOAT/i) {
		return { type => 'FT_FLOAT', len_min => 4, len_max => 4 };
	}

	if ($type =~ /^DOUBLE/i) {
		return { type => 'FT_DOUBLE', len_min => 8, len_max => 8 };
	}

	if ($type =~ /^ENUM/i) {
		return { type => 'FT_UINT', len_min => 1, len_max => 1 };
	}

	die "Unsupported type: $type!\n";
}
