#include <stdlib.h>
#include <stdio.h>

int main() {
	int var[] = {10, 20, 30};
	int i, *ptr[3];
	for (i=0; i<3; i++) {
		ptr[i] = &var[i];
	}
	
	for (i = 0; i < 3; i++) {
		printf("Val is var[%d] = %d\n", i, *ptr[i]);
	}
	return 0;
}
