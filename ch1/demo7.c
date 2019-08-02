#include <stdio.h>

int power(int base, int n);
void dft(int n);

// 1.7 函数
main()
{
    for (int i = 0; i < 10; i++)
        printf("%d %4d %6d\n", i, power(2, i), power(-3, i));
}

// 求幂
int power(int base, int n)
{
    int i, res;
    res = 1;
    for (i = 0; i < n; i++)
        res *= base;
    return res;
}

void dft(n) // 函数实现时参数默认是 int 类型，最好别去掉
{
    printf("function argument type default int\n");
}