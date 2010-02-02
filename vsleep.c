#include "vsleep.h"

void vsleep(unsigned int sec) {
	unsigned int i, q, digit, base;
	int j;

	digit = getDigit(sec);
	q = sec;
	for (j = digit-1 ; j >= 0; j--) {
		base  = (int)(pow(10.0, (double)j));
		printf("%d", q / base);
		q %= base;
	}

	for (i = sec; i > 0; i--) {
		sleep(1);

		if (i % 10 == 9) {
			digit = getDigit(i);
			for (j = digit; j >= 0; j--) {
				printf("\b");
			}
			q = i;
			for (j = digit-1 ; j >= 0; j--) {
				base  = (int)(pow(10.0, (double)j));
				printf("%d", q / base);
				q %= base;
			}
			printf(" \b");
		} else {	
			printf("\b%d", i % 10);
		}
		fflush(stdout);
	}
	printf("\b");
	fflush(stdout);
}

unsigned int getDigit(unsigned int sec) {
	unsigned int digit = 0;

	if ((sec / 10) == 0) {
		return 1;
	} else {
		digit += getDigit(sec / 10);
	}
	digit++;

	return digit;
}
