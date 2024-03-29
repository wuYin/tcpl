#include <stdio.h>
#include <stdlib.h>

// 2.9 按位运算符
main()
{
    printf("%04o\n", 0571 & 0177); // 0171 // 屏蔽某些二进制位
    printf("%04o\n", 0511 | 0707); // 0717 // 将某些二进制位置为 1
    printf("%04o\n", 0111 ^ 0101); // 0010 // 相异为 1，相同为 0
    printf("%d\n", 3 << 3);        // 24   // 0011 -> 1100
    printf("%d\n", 24 >> 3);       // 3    // 1100 -> 0011
    printf("%d\n", ~0110);         // -73
}
