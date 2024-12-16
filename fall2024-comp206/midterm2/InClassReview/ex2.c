#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Similar to ex1 but we are goint to use strtol
	// strtol returns pointer to first character that dosen't parse
	// call it, find the space using the pointer where there is the space
	// then call again where the space was and get the next argument
	char *arg = argv[1];
	char *endptr;
	int total = 0;

	while (1) {
		total += strtol(arg, &endptr, 10);
		// we pass address because we want to assign the address of the endptr
		// 	we want this value that strtol, not assigning it or anything
		// 	we will now have this address
		if (*endptr == '\0') break;
		// fine to loop again because strtol ignores any leading whitespace at
		arg = endptr;
	}
}

