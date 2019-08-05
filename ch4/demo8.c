#include <stdio.h>

// 4.8 程序块结构
main()
{
    int x = 10;

    {
        int x = 100; // 代码块 {} 内部会屏蔽外部的同名变量
        x++;
    }

    printf("x = %d\n", x); // 10
}
