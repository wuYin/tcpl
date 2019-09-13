#include <stdio.h>

// 6.1 结构的基本知识
struct point {
	int x;
	int y;
};

// 结构可以嵌套
struct rect {
	struct point pt1;
	struct point pt2;
};

int main() {
	struct point x = {2, 2};
	struct point y = {3, 3};
	printf("%d\n", x.x - y.x); // -1

	struct rect screen;
	printf("%d\n", screen.pt1.x); // 0
}


int f() {
	return 1;
}