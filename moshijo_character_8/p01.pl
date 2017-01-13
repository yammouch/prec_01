use strict;
use warnings;
#use Data::Dumper;

my $str = <STDIN>;

$str =~ m/(\S+)(\s+)(\S+)/;

my @cur = split(/\//, $1);
my @rel = split(/\//, $3);
shift(@cur);

#print Dumper [@cur];

for (my $i = 0; $i < @rel; $i++) {
  if ($rel[$i] eq '..')   { pop @cur; }
  elsif ($rel[$i] eq '.') { ;}
  else                    { push @cur, $rel[$i];}
}

print '/' . join('/', @cur) . "\n";

#print Dumper [@cur];
#print Dumper [@rel];
