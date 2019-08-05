#include <stdio.h>

// 读取输入行到 s 中，返回长度
int getLine(char s[], int limit)
{
    int c, i;
    i = 0;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
    return i; // 加上上方的 \0 长度为 i+1
}