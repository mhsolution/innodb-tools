#!/usr/bin/env perl

use strict;
use DBI;
use Data::Dumper;
use POSIX;
use Getopt::Long;

#----------------------------------------------------------------
# Parse command line

# Defaults
my $db_name = "test";
my $db_host = "127.0.0.1";
my $db_port = 3306;
my $db_user = "root";
my $db_pass = "";
my $help = 0;

# Parse options
my $res = GetOptions ("db=s"       => \$db_name,
                      "host=s"     => \$db_host,
                      "port=i"     => \$db_port,
                      "user=s"     => \$db_user,
                      "password=s" => \$db_pass,
                      "help|?"     => \$help
                     );

Usage() if !$res || $help;

#----------------------------------------------------------------
# Connect to mysql

my $dsn = "DBI:mysql:database=$db_name;host=$db_host;port=$db_port";
my $dbh = DBI->connect($dsn, $db_user, $db_pass);

Usage("Can't connect to mysql!") unless $dbh;

#----------------------------------------------------------------
# Dump tables definitions
my $sth = $dbh->prepare("SHOW TABLES");
$sth->execute;

print("#ifndef table_defs_h\n#define table_defs_h\n\n");
print("// Table definitions\ntable_def_t table_definitions[] = {\n");

while (my $row = $sth->fetchrow_arrayref) {
	my $table = $row->[0];

	# Skip if it is not an innodb table
	next unless(GetTableStorageEngine($table) =~ /innodb/i);

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

print("};\n\nconst int table_definitions_cnt = sizeof(table_definitions) / sizeof(table_def_t);\n\n");
print("#endif\n");

exit(0);

#------------------------------------------------------------------
sub DumpTableDef($$$) {
	my $table = shift;
	my $fields = shift;
	my $pk_fields = shift;

	print("\t{\n\t\tname: \"$table\",\n\t\t{\n");
	
	# Dump all PK fields
	foreach my $pk_field (@$pk_fields) {
		DumpField($table, FindFieldByName($fields, $pk_field->{Column_name}));
	}
	
	# Dump system PK if no PK fields found
	if (scalar(@$pk_fields) == 0) {
		DumpFieldLow(Name => 'DB_ROW_ID', ParsedType => 'FT_INTERNAL', FixedLen => 6, Null => 0);
	}
	
	# Dump 2 more sys fields
	DumpFieldLow(Name => 'DB_TRX_ID', ParsedType => 'FT_INTERNAL', FixedLen => 6, Null => 0);
	DumpFieldLow(Name => 'DB_ROLL_PTR', ParsedType => 'FT_INTERNAL', FixedLen => 7, Null => 0);
	
	# Dump the rest of the fields
	foreach my $field (@$fields) {
		DumpField($table, $field) unless $field->{Key} eq 'PRI';
	}

	print("\t\t\t{ type: FT_NONE }\n");
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
	
	printf("\t\t\t{ /* %s */\n", $info{Type});
	printf("\t\t\t\tname: \"%s\",\n", $info{Name});
	printf("\t\t\t\ttype: %s,\n", $info{ParsedType});

	if ($info{FixedLen}) {
		printf("\t\t\t\tfixed_length: %d,\n", $info{FixedLen});
	} else {
		printf("\t\t\t\tmin_length: %d,\n", $info{MinLen});
		printf("\t\t\t\tmax_length: %d,\n", $info{MaxLen});
	}
	
	printf("\n");
	
	if ($info{ParsedType} eq 'FT_TEXT' || $info{ParsedType} eq 'FT_CHAR') {
		printf("\t\t\t\thas_limits: TRUE,\n");
		printf("\t\t\t\tlimits: {\n");
		printf("\t\t\t\t\tchar_min_len: 0,\n");
		printf("\t\t\t\t\tchar_max_len: %d,\n", $info{MaxLen});
		printf("\t\t\t\t\tchar_ascii_only: TRUE\n");
		printf("\t\t\t\t},\n\n");
	}

	if ($info{ParsedType} eq 'FT_INT' && $info{Name} =~ /id$/i) {
		printf("\t\t\t\thas_limits: TRUE,\n");
		printf("\t\t\t\tlimits: {\n");
		printf("\t\t\t\t\tint_min_val: -30000,\n");
		printf("\t\t\t\t\tint_max_val: 30000\n");
		printf("\t\t\t\t},\n\n");
	} 

	if ($info{ParsedType} eq 'FT_UINT' && $info{Name} =~ /id$/i) {
		printf("\t\t\t\thas_limits: TRUE,\n");
		printf("\t\t\t\tlimits: {\n");
		printf("\t\t\t\t\tuint_min_val: 0,\n");
		printf("\t\t\t\t\tuint_max_val: 30000\n");
		printf("\t\t\t\t},\n\n");
	} 

	if ($info{ParsedType} eq 'FT_ENUM') {
		printf("\t\t\t\thas_limits: TRUE,\n");
		printf("\t\t\t\tlimits: {\n");
		printf("\t\t\t\t\tenum_values_count: %d,\n", scalar(@{$info{Values}}));
		printf("\t\t\t\t\tenum_values: { \"%s\" }\n", join('", "', @{$info{Values}}));
		printf("\t\t\t\t},\n\n");
	} 

	printf("\t\t\t\tcan_be_null: %s\n", $info{Null} ? 'TRUE' : 'FALSE');
	printf("\t\t\t},\n");
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
	
	$info{Type} = $field->{Type};
	$info{Values} = $type_info->{values};
	$info{ParsedType} = $type_info->{type};
	$info{MinLen} = $type_info->{min_len};
	$info{MaxLen} = $type_info->{max_len};
	$info{FixedLen} = $type_info->{fixed_len};
	
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
sub GetTableStorageEngine($) {
    my $table = shift;
    my $sth = $dbh->prepare("SHOW TABLE STATUS LIKE '$table'");
    $sth->execute;
    my $row = $sth->fetchrow_hashref;
    return $row->{Engine};
}

#------------------------------------------------------------------
sub Usage {
    my $msg = shift;
    if ($msg) {
        print "Error: $msg\n";
    }

    print "Usage: $0 [options]\n" .
          "Where options are:\n" .
          "\t--host     - mysql host\n" .
          "\t--port     - mysql port\n" .
          "\t--user     - mysql username\n" .
          "\t--password - mysql password\n" .
          "\t--db       - mysql database\n" .
          "\t--help     - show this help\n\n";
    exit(1);
}

#------------------------------------------------------------------
sub ParseFieldType($) {
	my $type = shift;
	
	if ($type =~ /DATETIME/i) {
		return { type => 'FT_DATETIME', fixed_len => 8 };
	}

	if ($type =~ /TIMESTAMP/i) {
		return { type => 'FT_UINT', fixed_len => 4 };
	}

	if ($type =~ /DATE/i) {
		return { type => 'FT_DATE', fixed_len => 8 };
	}

	if ($type =~ /^TINYINT/i) {
		return { type => 'FT_INT', fixed_len => 1 };
	}

	if ($type =~ /^SMALLINT/i) {
		return { type => 'FT_INT', fixed_len => 2 };
	}

	if ($type =~ /^MEDIUMINT/i) {
		return { type => 'FT_INT', fixed_len => 3 };
	}

	if ($type =~ /^INT/i) {
		return { type => 'FT_INT', fixed_len => 4 };
	}

	if ($type =~ /^BIGINT/i) {
		return { type => 'FT_INT', fixed_len => 8 };
	}

	if ($type =~ /(.*)CHAR\((\d+)\)/i) {
		return { type => 'FT_CHAR', min_len => ($1 ne '' ? 0 : $2), max_len => $2 };
	}

	if ($type =~ /^TINYTEXT$/i) {
		return { type => 'FT_TEXT', min_len => 0, max_len => 255 };
	}

	if ($type =~ /^TEXT$/i) {
		return { type => 'FT_TEXT', min_len => 0, max_len => 65535 };
	}

	if ($type =~ /^MEDIUMTEXT$/i) {
		return { type => 'FT_TEXT', min_len => 0, max_len => 16777215 };
	}

	if ($type =~ /^LONGTEXT$/i) {
		return { type => 'FT_TEXT', min_len => 0, max_len => 4294967295 };
	}

	if ($type =~ /^FLOAT/i) {
		return { type => 'FT_FLOAT', fixed_len => 4 };
	}

	if ($type =~ /^DOUBLE/i) {
		return { type => 'FT_DOUBLE', fixed_len => 8 };
	}

	if ($type =~ /^ENUM\(\'(.*)\'\)/i) {
		my @enum_values = split(/[\'\"]\,[\'\"]/, $1);
		return { type => 'FT_ENUM', fixed_len => 1, values => \@enum_values };
	}

	if ($type =~ /^DECIMAL\((\d+),\s*(\d+)\)/i) {
		my $len_bytes = ceil(($1-$2) * 4 / 9) + ceil($2*4/9);
		return { type => 'FT_CHAR', min_len => 0, max_len => $len_bytes };
	}

	die "Unsupported type: $type!\n";
}
