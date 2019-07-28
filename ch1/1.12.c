#include <stdio.h>

#define IN 1  // 在单词内
#define OUT 0 // 在单词外

// 算法关键：设立标志位避开连续的空白符
main()
{
	int c, state;
	state = OUT;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN)
			{
				state = OUT; // 单词结束
				putchar('\n');
			}
		}
		else
		{
			if (state == OUT)
			{
				state = IN;
			}
			putchar(c);
		}
	}
}