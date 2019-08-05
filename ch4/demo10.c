#include <stdio.h>

void putd(int n);

// 4.10 递归
main()
{
    putd(123); // 先递归再回溯
}

// 用递归打印十进制数
void putd(int n)
{
    if (n < 0)
    {
        n = -n;
        putchar('-');
    }
    if (n / 10)
        putd(n / 10);

    putchar(n % 10 + '0');
}