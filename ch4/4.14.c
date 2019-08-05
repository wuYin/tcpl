#include <stdio.h>

// 用宏实现 swap(t, x, y)
#define swap(t, x, y) \
    {                 \
        t tmp = x;    \
        x = y;        \
        y = tmp;      \
    }

// 宏的本质是对值进行替换
main()
{
    int x = 1;
    int y = 2;
    swap(int, x, y);
    printf("%d, %d\n", x, y); // 2, 1
}
