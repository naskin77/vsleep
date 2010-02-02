#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "vsleep.h"

int main(int argc, char *argv[]) {
	unsigned long long int sec;

	sec = 120;

	printf("befor sleep\n");
	vsleep(sec);
	printf("after sleep\n");

	return 0;
}
