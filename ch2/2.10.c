#include <stdio.h>

char lower(char c);

// 使用条件表达式实现 lower(char c) 函数
main()
{
    printf("lower: %c\n", lower('K')); // k
}

char lower(char c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}