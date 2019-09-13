#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))

// 6.2 结构和函数
struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

struct string {
	int len;
	char *s;
};

int main() {
	struct point p = {1, 1};
	struct point *pp = &p;
	printf("%d %d\n", (*pp).x, pp->y); // 1

	struct string s = {3, "ADG"};
	struct string *sp = &s;
	++sp->len;               // -> 的优先级更高
	printf("%d\n", sp->len); // 4
	printf("%c\n", *sp->s);  // A // 读取首个字符
	printf("%c\n", *sp->s++); // A
	printf("%c\n", *sp++->s); // D // 先读取 s 的值，在上一步已经被修改
}

// 创建点
struct point makePoint(int x, int y) {
	struct point tmp;
	tmp.x = x;
	tmp.y = y;
	return tmp;
}

// 两点相加
struct point addPoint(struct point p1, struct point p2) {
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

// 判断点是否在矩形内
int ptInRect(struct point p, struct rect r) {
	return p.x >= r.pt1.x && p.x < r.pt2.x
		   && p.y >= r.pt1.y && p.y < r.pt2.y;
}

// 校正矩形
struct rect canonRect(struct rect r) {
	struct rect tmp;
	tmp.pt1.x = min(r.pt1.x, r.pt2.x);
	tmp.pt1.y = min(r.pt1.y, r.pt2.y);
	tmp.pt2.x = max(r.pt1.x, r.pt2.x);
	tmp.pt2.y = max(r.pt1.y, r.pt2.y);
	return tmp;
}

