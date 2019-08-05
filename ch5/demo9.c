#include <stdio.h>

// 5.9 指针与多维数组
main()
{
    // 字符指针数组常用场景：作为字符串数组存放不同长度字符串
    char *a[2][2];
    char *b[2];
    printf("%d, %d\n", sizeof(a), sizeof(b)); // 32 16
}