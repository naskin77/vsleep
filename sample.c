#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "vsleep.h"

int main(int argc, char *argv[]) {
	unsigned long long int sec;

	if (argc < 2) {
		printf("usage: %s seconds\n", argv[0] );
		exit(1);
	}

	if (!isdigit(*argv[1])) {
		fprintf(stderr, "argument is not numeric.\n");
		exit(1);
	}
	printf("befor sleep\n");
	sec = atol(argv[1]);

	vsleep(sec);
	
	printf("after sleep\n");

	return 0;
}
