#include <stdio.h>

// v2: 使用
main()
{
	int c;

	// C 语言中赋值表达式是有值的，即所赋的值
	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}
}