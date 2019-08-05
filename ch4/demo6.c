#include <stdio.h>

void incr1();
void incr2();

// 4.6 静态变量
// static 关键字可限定全局变量、函数仅在所定义的文件内部使用，对其他文件不可见
// static 也可用于函数内部定义局部变量，但其生命周期不跟随函数的调用而创建和释放
main()
{
    for (int i = 0; i < 3; i++)
        incr1(), incr2();
}

void incr1()
{
    static int n = 1;
    printf("incr1: %d\n", n++); // 1 2 3
}

void incr2()
{
    int n = 1;
    printf("incr2: %d\n", n++); // 1 1 1
}
