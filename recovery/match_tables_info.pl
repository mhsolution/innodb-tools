#!/usr/bin/env perl

use strict;
use Data::Dumper;

# Check pages dir
if (scalar(@ARGV) < 1) {
	print("Usage: $0 <tables_directory>\n");
	exit(1);
}

my $dir_name = $ARGV[0];
print "Processing directory: '$dir_name'...\n";

my $page_descriptions = {};

# Read pages description
my $res = open(F, "$dir_name/tables.description");
unless ($res) {
	print "Can't open $dir_name/tables.description file!\n";
	exit(1);
}

# Parse descriptions
while(<F>) {
	chomp;
	next if (/^#/ || /^$/);
	
	my ($table, $fields) = split(/\s*:\s*/);
	my @fields = split(/\s*,\s*/, $fields);
	
	my @table_info = ();
	foreach my $field (@fields) {
		chomp($field);
		unless ($field =~ /^([\w\d\-\_]+)\s*=\s*([\w\d]+)\((\d*)\)/i) {
			print "Invalid field description for table '$table': $field\n";
			exit(1);
		}
		
		push (@table_info, {'name' => $1, 'type' => $2, 'size' => $3});
	}
	$page_descriptions->{$table} = \@table_info;
}

close(F);

print "Found " . scalar(keys(%$page_descriptions)) . " table descriptions\n";



1;
