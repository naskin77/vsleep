#!/opt/local/bin/perl

use strict;
use warnings;
use constant DEBUG => 1;
use vsleep qw(vsleep);

print "before sleep\n";
vsleep(123);
print "after sleep\n";

vsleep("a1");
