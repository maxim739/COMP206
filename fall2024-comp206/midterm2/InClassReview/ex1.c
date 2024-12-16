#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *arg = argv[1];
	
	int total = 0;

	// do while loop instead of normal one
	for (int i = 0; arg[i] != '\0'; i++) {
		if ('0' <= arg[i] && arg[i] <= '9') {	// Single quotes will convert 0 to ascii
							// Double quotes will ~~~~~~~
			total += arg[i] - '0';
		}
	}
	printf("%d\n", total);
}
