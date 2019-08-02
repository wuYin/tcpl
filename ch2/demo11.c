#include <stdio.h>

// 定义宏
#define MAX(a, b) (a > b) ? (a) : (b)

// 2.11 条件表达式，即三元运算符
main()
{
    printf("%d\n", MAX(1, 2)); // 2
}