#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 7.1 实现大小写转换
// mv a.out tolower
int main(int argc, char *argv[]) {
	int forLower = strstr(argv[0], "lower") != NULL ? 1 : 0;
	int c;
	while ((c = getchar()) != EOF)
		putchar(forLower ? tolower(c) : toupper(c));
}