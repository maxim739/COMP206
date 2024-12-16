#include "includer.h"

typedef struct Point{
	union type{
		int num;
		char let;
		char *name;
	}type;
	int tag;
}Point;

typedef struct PointArr{
	Point *pt;
	int size;
	int cap;
}PointArr;

void init(PointArr points, int size) {
	points.size = 0;
	points.cap = size;
	points.pt = malloc(size * sizeof(Point));
}

void destroy(PointArr points) {
	free(points.pt);
	points.pt = NULL;
	points.size = 0;
	points.cap = 0;
}

void append(PointArr points, Point point) {
	if (points.size == points.cap) {
		// Need to resize
		int old_cap = points.cap;
		Point old_arr[points.size];

		for (int i = 0; i < points.size; i++ ) {
			old_arr[i] = points.pt[i];
		}

		destroy(points);
		init(points, old_cap * 2);

		for (int i = 0; i < old_cap; i++) {
			append(points, old_arr[i]);
		}
	} else {
		points.pt[points.size] = point;
		points.size++;
	}
}

int main() {
	Point p1;
	p1.tag = 1;
	p1.type.num = 10;

	Point p2;
	p2.tag = 2;
	p2.type.let = 'c';

	Point p3;
	char name[] = "Hello";
	p3.tag = 3;
	p3.type.name = name;

	PointArr points1;
	init(points1, 2);
	append(points1, p1);
	append(points1, p2);
	append(points1, p3);
}	
