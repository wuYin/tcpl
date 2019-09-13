#include <stdio.h>

// 5.1 指针与地址
main()
{
    int *ip;
    // printf("%d\n", *ip); // 段错误，仅声明的指针指向的值是无效的

    int x = 1, y = 2;
    ip = &x;
    y = *ip;
    *ip = 0;
    printf("%d, %d\n", x, y); // 0, 1

    // int a = *ip++;           // 指针本身也是变量，可以参与运算，此时的
    int a = (*ip)++;            // *取地址运算符与 ++/-- 优先级相同，但必须遵循从右自左的结合顺序，所以操作值时 () 是必需的
    printf("%d, %d\n", a, *ip); // 0, 1

    int *iq = ip; // 二者指向同一对象
}