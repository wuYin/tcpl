#include <stdio.h>

#define MAX_LINE 1000

void reverse(char s[]);
int getLine(char s[], int limit);

// 输入字符串将其反转
main()
{
    char line[MAX_LINE];
    while (getLine(line, MAX_LINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
}

// 反转 s 字符串，需要剔除尾部的 \0 并保留换行符
void reverse(char s[])
{
    int i = 0;
    // 先定位字符串尾部
    // while (s[i++] != '\0') // bug
    //     ;

    while (s[i] != '\0') // 以上两种写法是有区别的，前者不论条件是否成立 i+=1 都会执行
        i++;
    i--;

    // 尾部出现的换行符保留
    if (s[i] == '\n')
        i--;

    // swap
    char tmp;
    for (int j = 0; j < i; j++, i--)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int getLine(char s[], int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}