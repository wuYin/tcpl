#include <stdio.h>

// 验证 EOF 的值
main()
{
	int c;

	while (c = getchar() != EOF) // != 的优先级高于 =
	{
		printf("%d\n", c); // C 中 0 false / 1 true
		putchar(c);
	}
	printf("%x\n", c); // 0D
}