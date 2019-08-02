#include <stdio.h>

#define MAX_LINE 1000

int maxLen;
char line[MAX_LINE];
char longest[MAX_LINE]; // 定义全局变量

void copy(void);
int getLine(void);

// 1.10 外部变量与作用域
main()
{
    int len;
    // extern 声明一个不存在的外部变量将
    // extern int max; // Undefined symbols for architecture x86_64: "_max"
    extern int maxLen;
    extern char longest[];

    maxLen = 0;
    while ((len = getLine()) > 0)
        if (len > maxLen)
        {
            maxLen = len;
            copy();
        }

    if (maxLen > 0)
        printf("%s", longest);
    return 0;
}

void copy(void)
{
    int i = 0;
    while ((longest[i] = line[i]) != '\0') // 通过上下文隐式声明
        i++;
}

// 读取到的行字符串放入 line 全局变量中
int getLine(void)
{
    extern char line[]; // extern 声明使用外部变量，在其定义后使用可省略
    int c, i;
    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}