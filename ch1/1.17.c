#include <stdio.h>

#define MAX_LINE 1000 // 预分配的空间需有上限
#define MIN_LINE 80

// 打印长度超过 80 个字符的输入行
main()
{
    int n;
    char s[MAX_LINE];
    while ((n = getLine(s, MAX_LINE)) > 0)
        if (n > MIN_LINE)
            printf("%s", s);

    return 0;
}

// 从标准输入中读取一行放入 s 中并返回读取的长度
int getLine(char s[], int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') // 提前结束行
        s[i++] = '\n';

    s[i] = '\0';
    return i;
}