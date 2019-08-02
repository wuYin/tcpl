#include <stdio.h>

// 1.2 变量与算术表达式
/* 我是注释，可以出现在任何允许空白符出现的地方 */
main()
{
    // int f, c;
    float f, c;
    int lower, upper, step; // 声明：类型 变量表

    lower = 0;   // 温度表下限
    upper = 300; // 上限
    step = 20;   // 步长

    f = lower;
    while (f <= upper)
    {
        c = 5 * (f - 32) / 9;
        // printf("%d\t%d\n", f, c);
        // printf("%3d %6d\n", f, c); // 默认右对齐，加数字指明宽度

        printf("%3.f %6.1f\n", f, c);
        f = f + step;
    }

    // %M.Nf 最少为 M 不够则左填充空格，但小数点后最多 N 个数字精度，注意还有进位
    printf(":%5.2f:\n", 4.5678); // : 4.57:
}