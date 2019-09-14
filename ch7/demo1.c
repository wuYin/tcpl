#include <stdio.h>
#include <ctype.h>

// 7.1 标准输入输出
int main() {
	int c;
	while ((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}