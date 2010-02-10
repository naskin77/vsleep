#include <stdio.h>
#include "vsleep.h"


int main(int argc, char *argv[]) {
	unsigned long long int sec;

	printf("count down start\n");
	vsleep(120);
	printf("count down finish\n");

	return 0;
}
