#include "includer.h"

int main(int argc, char *argv[]) {
	FILE *infile;
	infile = fopen(argv[1], "rt");

	char buf[24];

	if (NULL == fgets(buf, sizeof(buf), infile)) {
		if (!feof(infile)) {
			perror("fgets");
			return 1;
		}
	}

	char *endptr;	// end ptr for the str
	
	float one = strtof(buf, &endptr);
	float two = strtof(endptr + 1, NULL);

	printf("one %f, two %f\n", one, two);

	return 0;
}
