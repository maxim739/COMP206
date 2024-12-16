#include "includer.h"

typedef struct dynarr{
	int size;
	int * arr;
	int cap;
}dynarr;

// Find count of number of lines so that we make the right sized array
int count_lines(int *count, FILE *file) {
	// Go through the file counting \n until we get to eof
	char buf[20];
	int cut = 0;
	while (1) {
		if (NULL == fgets(buf, sizeof(buf), file)) {
			if (feof(file)) {
				*count = cut;
				return 1;
			}
			else {
				perror("fgets");
				return 0;
			}
		}
		
		for (int i = 0; buf[i] != '\0'; i++) {
			if (buf[i] == '\n') {
				cut++;
			}
		}
	}
}

int longest_line(int *lineno, FILE *file) {
	int longest_line = -1;
	int curr_line = 0;
	int line_num = 1;
	char buf[256];

	while (1) {
		if (NULL == fgets(buf, sizeof(buf), file)) {
			if (feof(file)) {
				*lineno = longest_line;
				return 1;
			} else {
				perror("fgets");
				return 0;
			}
		}

		for (int i = 0; buf[i] != '\0'; i++) {
			if (buf[i] == '\n') {
				if (curr_line > longest_line) {
					longest_line = curr_line;
				}
				line_num++;
				curr_line = 0;
			} else {
				curr_line++;
			}
		}
	}
}	
	
int main(int argc, char *argv[]) {
	FILE *infile;
	infile = fopen(argv[1], "rt");
	int longest = 0;
	int *line = &longest;
	int worked = longest_line(line, infile);
	printf("Worked: %d\nLongest line is line %d\n", worked, longest);
	return 0;
}
