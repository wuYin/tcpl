#include <stdio.h>

// 将转移字符以可见方式输出
main()
{
	int c;
	while ((c = getchar()) != EOF)
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
}