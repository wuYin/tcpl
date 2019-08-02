#include <stdio.h>

#define MAX_LINE 1000

int getLine(char s[], int limit);
void copy(char to[], char from[]);

// 1.9 字符数组，即字符串
// 打印最长的输入行
main()
{
    int len, maxLen;
    char line[MAX_LINE], longestLine[MAX_LINE];

    maxLen = 0;
    while ((len = getLine(line, MAX_LINE)) > 0)
        if (len > maxLen)
        {
            maxLen = len;
            copy(longestLine, line);
        }

    // 存在最长行则输出
    if (maxLen > 0)
        printf("longest: %s", longestLine);

    return 0;
}

// 从标准输入中读取一行放入 s 中并返回读取的长度
int getLine(char s[], int limit)
{
    int i, c;
    // 循环退出条件：'\n' 或 i=limit-1
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') // 提前结束行
        s[i++] = '\n';

    s[i] = '\0';
    return i;
}

// 将字符从 from 复制到 to，假定 to 空间足够大
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}