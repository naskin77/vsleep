	package vsleep;

	use strict;
	use warnings;
	use vars qw(@ISA @EXPORT_OK);
	use Carp qw(croak);
	require Exporter;
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(vsleep);

	sub vsleep {
		my $sec = shift;
		my $digit = 0;
		my $base;
		my $i;
		my $j;
		my $mode = $|;
		$| = 1;

		croak("Argument \"$sec\" isn't numeric.") unless ($sec =~ /^[0-9]*$/);

		if (main->DEBUG) {
			printNumber($sec);
			for ($i = $sec; $i > 0; $i--) {
				sleep(1);
				if ($i % 10 == 9) {
					$_ = $i;
					$digit = tr/0-9//;
					for ($j = $digit; $j >= 0; $j--) {
						print "\b";
					}

					printNumber($i);
					print " \b";
				} else {
					print "\b" . $i % 10;
				}
			}
			print "\b";
		} else {
			sleep($sec);
		}
		$| = $mode;

		sub printNumber {
			my $sec = shift;
			$_ = $sec;
			my $digit = tr/0-9//;
	
			my $q = $sec;
			for (my $j = $digit-1; $j >= 0; $j--) {
				my $base = int(10 ** $j);
				print int($q / $base);
				$q %= $base;
			}
		}
	}

1;
