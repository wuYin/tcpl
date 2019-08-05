#include <stdio.h>

// 4.11 C 预处理器
// 长宏定义能用 \ 分割定义，宏只对记号进行替换
#define MAX(A, B) ((A) > (B)) \
                      ? (A)   \
                      : (B)

#define square(x) x *x
#undef square
#define square(x) (x) * (x)

#define dPrint(expr) printf(#expr " = %d\n", expr)

// 条件包含
#ifndef MIN
#define MIN(A, B) ((A) < (B)) ? (A) : (B)
#endif

// 取消宏定义
// #undef MAX // Undefined symbols for architecture x86_64: "_MAX", referenced from:

main()
{

    printf("MIN: %d\n", MIN(1, 2)); // 1

    // 使用宏需关注 ++/-- 额外带来的计算副作用
    int x = 1, y = 2;
    printf("max:%d\n", MAX(x++, y++)); // 3
    printf("%d, %d\n", x, y);          // 2 4

    // 宏定义使用 () 保证运算次序的正确性
    int z = 2;
    printf("square: %d\n", square(z + 1)); // 5 // 2+1*2+1 = 5

    // 宏定义的形参可加 # 前缀实现原样替换
    dPrint(y - x); // y - x = 2
}