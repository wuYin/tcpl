#include <stdio.h>

int x;

// 4.9 初始化
main()
{
    static int y;
    int z;

    // 全局变量和 static 静态变量初始化值为 0
    // 局部变量默认初始值不定，是无效的
    printf("%d, %d, %d\n", x, y, z); // 0 0 1

    int nums1[2] = {1};       // ok
    int nums2[2] = {1, 2, 3}; // 初始化表达式列表中元素个数超过指定个数：warning: excess elements in array initializer
    printf(nums2[2]);         // 越界

    char s1 = "demo";
    char s2 = {'d', 'e', 'm', 'o', '\0'}; // 尾部手动加 '0' 才与 s1 等效
}