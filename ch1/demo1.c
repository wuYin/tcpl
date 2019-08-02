#include <stdio.h>

// 1.1 入门
int main()
{
    printf("hello, world\n");

    // 分阶段输出长字符串，内部换行则 error: expected expression
    printf("hello, ");
    printf("world");
    printf("\n");
}