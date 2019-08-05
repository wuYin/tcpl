#include <stdio.h>
#include <stddef.h>

#define ALLOC_SIZE 10000

static char allocbuf[ALLOC_SIZE]; // 内存区域
static char *allocp = allocbuf;   // 下一个空闲起始位置
int strlen(char *s);

// 5.4 地址算术运算
main()
{
    int *p = 0;
    printf("%p, %d, %d\n", NULL, NULL, p == NULL); // 0x0, 0, true

    int nums1[] = {1, 3, 5};
    int nums2[] = {2, 4, 6};
    printf("%d\n", nums1 + 1 == nums2 + 2); // 0 // 指向不同数组的指针运算

    printf("%d\n", strlen("demo")); // 4
}

// 申请长为 n 的内存，返回指向 n 个字符的指针
char *alloc(int n)
{
    if (allocbuf + ALLOC_SIZE - allocp >= n) // 内存够分配
    {
        allocp += n;
        return allocp - n;
    }

    return 0; // 0 一定是无效地址
}

// 释放 p 指向的内存区域
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOC_SIZE)
        allocp = p;
}

// 指针与整数可加减
// 相同数组的两个指针可比较、可相减
// 指针可赋值 0，可与 0 比较（与 NULL 空指针比较）
int strlen(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s; // 间距
}