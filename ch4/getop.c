#include <stdio.h>
#include <ctype.h>
#include "calc.h"


#define NUMBER_FLAG '0'

// 获取下一个运算符或数字保存至 s，返回运算符或数字 flag
// 代码十分的精简
int getop(char s[])
{
    int c;
    // 跳过空白符
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    // 符号则返回
    if (!isdigit(c) && c != '.')
    {
        s[1] = '\0';
        return c;
    }

    int i = 0;
    // 采集整数
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch())) // s[0] 已采集数字或小数点，所以 ++i
            ;
    // 采集小数
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER_FLAG;
}
