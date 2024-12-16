#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person{
	int age;
	char name[30];
	union SPEC_DATA{
		struct {float eval; int position;}professor;
		struct {float GPA; int year;}student;
		struct {char level; float salary;}staff;
	}specific;
}people[100];	// 100 of these person structures are created

int main() {
	printf("Size is %ld\n", sizeof(people));
}
