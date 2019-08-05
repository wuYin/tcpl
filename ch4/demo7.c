#include <stdio.h>

// 只能声明为局部变量或函数形参
// register int v; // illegal storage class on file-scoped variable

// 4.7 寄存器变量
main()
{
    register int x = 10;      // 寄存器变量是不可寻址的
    printf("addr: %x\n", &x); // address of register variable requested
}

int sum(register int x, register int y) // 形参也可声明为寄存器变量
{
    return x + y;
}