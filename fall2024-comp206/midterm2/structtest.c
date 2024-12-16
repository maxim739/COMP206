#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NAME{
	char first[30];
	char last[30];
};

struct PERSON{
	struct NAME name;
	int age;
	float height;
	char arr[20];
};


int main() {
	struct PERSON a;
	strcpy(a.name.first, "John");
	strcpy(a.name.last, "Doe");
	printf("Age is %d height is %f name is %s\n", a.age, a.height, a.name.first);
	printf("Size is %ld\n", sizeof(a));
}
	
