#include "includer.h"
// Implimtent a dynamic array first

typedef struct dynarr{
	int *array;
	int size;
	int cap;
}dynarr;

void init(dynarr *arr, int size) {
	//printf("Created the array");
	(*arr).array = (int *)malloc(sizeof(int) * size);	// We are filling it with ints
	(*arr).size = 0;
	(*arr).cap = size;
	//printf("Cap is %d, size is %d\n", arr->cap, arr->size);
}


void destroy(dynarr *arr) {
	arr->size = 0;
	arr->cap = 0;
	free(arr->array);
	arr->array = NULL;
}

void append(dynarr *arr, int input) {
	//printf("adding to array");
	if (arr->size == arr->cap) {
		// We need to make bigger
		// Copy the array to tmp
		int tmp_arr[arr->cap];
		for (int i = 0; i < arr->cap; i++) {
			tmp_arr[i] = arr->array[i];
		}
		int old_cap = arr->cap;
		destroy(arr);
		init(arr, old_cap * 2);
		for (int i = 0; i < old_cap; i++) {
			append(arr, tmp_arr[i]);
		}
	} else {
		arr->array[arr->size] = input;
		arr->size++;
	}
}

int main(int argc, char **argv) {	// argv is a pointer to an array of pointers
	//printf("Doing sum");
	dynarr new;
	init(&new, 10);

	FILE *file;
	file = fopen(argv[1], "rt");
	char buf[256];

	while (NULL != fgets(buf, sizeof(buf), file)) {
		//char **endptr;
		//printf("%c\n", buf[0]);
		int in = strtol(buf, NULL, 10);
		//printf("in: %d\n", in);
		append(&new, in);
	}

	if (!feof(file)) {
		perror("fgets");
		return 1;
	}

	for (int i = 0; i < new.size; i++) {
		printf("%d\n", new.array[i]);
	}
	fclose(file);
	destroy(&new);
	return 0;	
}
