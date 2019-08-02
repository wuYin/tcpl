#include <stdio.h>

#define LOWER 0
#define UPPER 300 // 符号常量不是变量，无需预先声明
#define STEP 20

// 1.4 符号常量
main()
{
    for (int f = LOWER; f <= UPPER; f += STEP)
        printf("%3d %6.1f\n", f, (5.0 / 9.0) * (f - 32));
}