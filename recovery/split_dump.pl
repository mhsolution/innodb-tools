#!/usr/bin/env perl

$files = {};

mkdir("dump");

while(<>) {
	/(.*?)\t(.*)/;
	unless ($files->{$1}) {
		open $files->{$1}, ">dump/$1.csv";
	}
	$F = $files->{$1};
	print($F "$2\n");
}

