#include <stdio.h>
#include <stdlib.h>

void cat(FILE *file, FILE *out_file) {
	char buf[1024];
	while (1) {
		if (NULL == fgets(buf, sizeof(buf)-1, file)) {
			if (feof(file)) { return; }
			perror("fgets");
			exit(1);
		}
	// Otherwise print 1023 chars to stdout
	// printf("%s", buf);
	fputs(buf, out_file);
	}
}


int main(int argc, char *argv[]) {
	// Open the file
	// And output file
	FILE *input_file;
	FILE *output_file;

	if (argc == 1) {
		input_file = stdin;
		output_file = fopen("test_file.txt", "wt");
	} else {
		input_file = fopen(argv[1], "rt");	// Make the input file first
		output_file = fopen(argv[2], "wt");
		if (NULL == input_file || NULL == output_file) {
			perror("fopen");
			return 1;
		}
	}
	// Output file is always test_file.txt
	
	cat(input_file, output_file);
	return 0;
}
	

