#include <stdio.h>
#include <stdlib.h>

// 5.5 字符指针与函数
main()
{
    printf("%d\n", NULL == '\0');          // 1 // '\0' 数值上等于 NULL
    printf("%d\n", strcmp2("aba", "aaa")); // 1

    // * 与 ++/-- 实现标准进栈出栈 // 三者优先级相同，但自右向左结合
    int stack[3] = {1, 2};
    int *p = stack;
    *p++ = 3;       // 进栈
    int top = *--p; // 出栈
}

// 指针比较字符串
int strcmp2(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;

    return *s - *t;
}

// 数组比较字符串
int strcmp1(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return i;

    return s[i] - t[i];
}

// 字符数组实现的字符串拷贝
void strcpy1(char *dst, char *src)
{
    int i = 0;
    while (dst[i++] = src[i++]) // ++ 虽有副作用，但仅影响局部变量 i
        ;
}

// 字符指针实现拷贝
void strcpy2(char *dst, char *src)
{
    while (*dst++ = *src++) // 精简字符串尾部判断
        ;
}