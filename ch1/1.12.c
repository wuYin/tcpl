#include <stdio.h>

#define IN 1
#define OUT 0

// 将输入以单词形式输出，即遇到空白符就将单词输出
// 思路：和单词计数一样设立是否正在构建新单词的状态 state 变量
main()
{
	int c, state;
	state = OUT;

	while ((c = getchar()) != EOF)
	{
		// && 比 || 大一个优先级
		if ((c == ' ' || c == '\t' || c == '\n') && state == IN)
		{
			state = OUT;
			putchar('\n');
		}
		else
		{
			if (state == OUT) // 重新构建新单词
				state = IN;
			putchar(c);
		}
	}
}