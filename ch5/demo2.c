#include <stdio.h>
#include <ctype.h>
#include "ch5.h"

void swap(int *x, int *y);

// cc demo2.c getch.c && ./a.out
main()
{
    int x = 1, y = 5;
    swap(&x, &y);
    printf("%d, %d\n", x, y); // 5 1

    int i, nums[3], getint(int *);
    for (i = 0; i < 3 && getint(&nums[i]) != EOF; i++)
        ;
    printf("%d, %d, %d\n", nums[0], nums[1], nums[2]);
}

// 交换两个变量的值
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// 将输入中的下一个整数赋值给 pn
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;

    // 非法输入
    if (!isdigit(c) && c != EOF && c != '-' && c != '+')
    {
        ungetch(c);
        return 0;
    }

    sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}