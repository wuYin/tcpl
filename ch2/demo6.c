#include <stdio.h>

// 2.6 关系运算符与逻辑运算符
main()
{
    // && 优先级高于 ||
    printf("compare: %d\n", 1 || 1 && 0); // 1

    // 关系表达式的结果值：真为1，假为0
    printf("true:  %d\n", 1 == 1); // 1
    printf("false: %d\n", 0 == 1); // 0
}