#include <stdio.h>

// v1: 将输入复制到输出
main() {
	int c;

	c = getchar();
	while(c != EOF) { // Ctrl+D 
		putchar(c);
		c = getchar();
	}

	printf("%d\n", EOF); // -1
}