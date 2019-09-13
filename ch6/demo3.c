#include <stdio.h>

struct key {
	char *word; // map 结构
	int count;
} keytab[] = {
		{"for", 0},
		"break", 0, // 简单变量可以省去内部括号
};

//#define NKEYS (sizeof keytab / sizeof (struct key))
#define NKEYS (sizeof keytab / sizeof keytab[0])

// 6.3 结构数组
int main() {
	printf("%d\n", NKEYS); // 2

	struct user {
		char c;
		int age;
	} u;
	printf("%d\n", sizeof(u)); // 内存对齐 8 而非 5
}