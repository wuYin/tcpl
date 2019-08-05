#include <stdio.h>

// 用缓冲区模拟预读取一个字符
#define BUF_SIZE 100
char buf[BUF_SIZE];
int bufNext = 0; // buf 中下一个空闲位置

// 取下一个字符
int getch(void)
{
    return (bufNext > 0) ? buf[--bufNext] : getchar();
}

// 将字符回写到缓冲区
// 比如 1 1 + 的输入，需把 1 1 中间的空格符返回缓冲区
void ungetch(char c)
{
    if (bufNext > BUF_SIZE)
        printf("ungetch: too many char");
    else
        buf[bufNext++] = c;
}