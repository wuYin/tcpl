#include <stdio.h>

// 2.10 赋值运算符与表达式
main()
{
    // 赋值运算符右侧是整体参与运算的
    int x, y;
    x = y = 1;
    x *= y + 2;           // 等价于 x = (x) * (y+1)
    printf("x: %d\n", x); // 3
}