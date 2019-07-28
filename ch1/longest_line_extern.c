#include <stdio.h>

// 定义符号常量
#define MAXLINE 1000

// 定义全局变量
int maxLen;
char curLine[MAXLINE];
char maxLine[MAXLINE];

// 定义函数原型
int getLine(void); // 空参数列表最好还是 void 显式标识出
void copy(void);

main()
{
	// 打印输入的最长行
	int max, len;

	max = 0;
	while ((len = getLine()) > 0)
	{
		if (len > max)
		{
			copy();
			max = len;
		}
	}
	if (max > 0)
	{
		printf("%s", maxLine);
	}
	return 0;
}

// 行复制
void copy(void)
{
	int i;

	extern char curLine[], maxLine[];
	i = 0;
	while ((maxLine[i] = curLine[i]) != '\0')
	{
		i++;
	}
}

// 读取输入的一行
int getLine(void)
{
	int c, i;

	// 与 PHP 的 global 声明使用全局变量类似
	extern char curLine[];
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		curLine[i] = c;
	}
	if (c == '\n')
	{
		curLine[i] = '\n';
		i++;
	}
	curLine[i] = '\0';
	return i;
}