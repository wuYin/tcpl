#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxLine);
void copy(char src[], char dst[]);

// 打印最长的输入行
main()
{
	int curLen, maxLen;
	char curLine[MAXLINE], maxLine[MAXLINE];

	maxLen = 0;
	while ((curLen = getLine(curLine, MAXLINE)) > 0)
	{ // 当前行还有字符则继续
		if (curLen > maxLen)
		{
			maxLen = curLen;
			copy(curLine, maxLine);
		}
	}
	if (maxLen > 0)
	{
		printf("%s\n", maxLine);
	}
	return 0;
}

// 每行最多读取 maxLine 个字符到 s 字符数组中，返回其长度
int getLine(char s[], int maxLine)
{
	int c, i;

	for (i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return i;
}

// 假设长度：dst >= src
void copy(char src[], char dst[])
{
	int i;
	i = 0;

	// 只要还未复制到最后一个字符就继续
	while ((dst[i] = src[i]) != '\0')
	{
		i++;
	}
}
