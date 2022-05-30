#!/usr/bin/perl
# perl map_gen.pl x y 〇の割合 y.ox
use warnings;
use strict;
use utf8;
use open ":utf8";
binmode STDIN, ':encoding(cp932)';
binmode STDOUT, ':encoding(cp932)';
binmode STDERR, ':encoding(cp932)';

die "program x y density" unless (scalar(@ARGV) == 6);
my ($x, $y, $density, $empty, $full, $filename) = @ARGV;

open(DATAFILE, "+>>", $filename) or die "Failed to open a file\n";
print DATAFILE $y . $empty . "o" . $full . "\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print DATAFILE $full;
		}
		else {
			print DATAFILE $empty;
		}
	}
	print DATAFILE "\n";
}
close(DATAFILE);
