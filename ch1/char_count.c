#include <stdio.h>

// v1: 统计输入的字符数
main() {
	long nc;

	nc = 0;
	while(getchar() != EOF) {
		++nc;
	}

	printf("%ld\n", nc);
}