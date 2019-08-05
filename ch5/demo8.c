#include <stdio.h>

// 5.8 指针数组的初始化
main()
{
    // 数组的元素为指针即可
    static char *ms[] = {
        "unknown",
        "1",
        "2",
        "3",
    };

    printf("ms[1]: %s\n", ms[1]);
}