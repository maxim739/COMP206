#include "includer.h"

typedef struct Coord{
	float x;
	float y;
}Coord;

typedef struct CoordArray{
	Coord *arr;
	int size;
	int cap;
}CoordArray;

void initCoord(CoordArray *arr, int size) {
	(*arr).arr = (Coord *)malloc(size * sizeof(Coord));
	arr->size = 0;
	arr->cap = size;
}

void addCoord(CoordArray *arr, Coord coord) {
	if (arr->size == arr->cap) {
		// We need to resize here
		// We use realloc here but reimpliment using malloc
		arr->cap = arr->cap * 2;
		(*arr).arr = (Coord *)realloc(arr->arr, arr->cap * sizeof(Coord));
	}
	arr->arr[arr->size] = coord;
	arr->size++;
}

void freeCoord(CoordArray *arr) {
	arr->size = 0;
	arr->cap = 0;
	free(arr->arr);	// We free the dynamic array within the structure
	arr->arr = NULL;
}



int line_count(FILE *file) {
	// Find the number of coords in the file to know how big to make the arr
	int linecount = 0;
	char buf[1024];
	
	while (NULL != fgets(buf, sizeof(buf), file)) {
		// While the file is not null
		for (int i = 0; buf[i] != '\0'; i++) {
			if (buf[i] == '\n') {
				linecount++;
			}
		}
	}
	if (!feof(file)) {	// The file didnt end because it had to
		perror("fgets");
		return -1;
	}

	//Now we know how many lines are in the file, and how many coords we need
	return linecount;
}

int parse_coord(struct Coord *coord, char *line) {
	char *endptr;
	coord -> x = strtof(line, &endptr);
	coord -> y = strtof(endptr + 1, NULL);
	return 0;
}

int parse_coord_file(CoordArray *arr, FILE *file) {
	int arrindex = 0;
	char buf[64];

	while (fgets(buf, sizeof(buf), file) != NULL) {
		parse_coord(&(*arr).arr[arrindex], buf);
		arrindex++;
	}
	
	if (!feof(file)) {
		perror("Fgets");
		return 1;
	} else { return 0;}	
}

Coord centriod(CoordArray *arr) {
	// Need running total and size of arr to make an average
	Coord centroid;
	float x_sum = 0;
	float y_sum = 0;

	// int size = sizeof(arr)/sizeof(arr[0]);
	int size = arr -> size;

	for (int i = 0; i < size; i++) {
		x_sum += (*arr).arr[i].x;
		y_sum += arr->arr[i].y;
	}

	centroid.x = x_sum / size;
	centroid.y = y_sum / size;

	return centroid;
}

int main(int argc, char *argv[]) {
	FILE *infile;
	infile = fopen(argv[1], "rt");
	int line_nums = line_count(infile);

	CoordArray arr1;
	initCoord(&arr1, line_nums);
	parse_coord_file(&arr1, infile);
	Coord center = centriod(&arr1);
	printf("The average coord is (%f, %f)", center.x, center.y);
	return 0;

}
