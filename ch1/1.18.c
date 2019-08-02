#include <stdio.h>

#define MAX_LINE 1000

// 读取输入，删除行尾的空格和制表符，删除完全是空格的行
// 思路：对字符数组从后向前处理
main()
{
    int n;
    char line[MAX_LINE];

    while ((n = getLine(line, MAX_LINE)) > 0)
        if (trim(line) > 0)
            printf("%s", line);
}

// 处理尾部空格或制表符
int trim(char s[])
{
    int i = 0;
    while (s[i] != '\n')
        i++;
    i -= 1; // i 指向最后一个字符

    // 向前找第一个非空白符
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        i--;

    // 删除其后的空白符
    if (i >= 0)
    {
        s[++i] = '\n'; // 将上边的尾部换行符挪到此处
        s[++i] = '\0'; // 手动加边界
    }

    return i;
}

// 读取最多 limit 个字符到 s 中
int getLine(char s[], int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
    return i;
}