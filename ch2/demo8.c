#include <stdio.h>

void squeeze(char s[], char c);
void strcat(char dst[], char src[]);

// 2.8 自增与自减运算符
main()
{
    // i++ 后缀自增运算符，先使用 i 的旧值再自增 1
    // ++i 前缀自增运算符，i 先自增 1 再使用 i 的新值
    int i = 0;
    int x = i++;
    printf("x:%d, i:%d\n", x, i); // 0 1
    int y = ++x;
    printf("y:%d, x:%d\n", y, x); // 1 1

    // ++ 与 -- 只能用于变量，不能用于表达式
    // printf("%d\n", i++ ++);

    char s[] = "hello";
    squeeze(s, 'l');
    printf("squeeze: %s\n", s); // heo

    char s1[10] = "abc";
    char s2[] = "DEF";
    strcat(s1, s2);
    printf("strcat: %s\n", s1); // abcDEF
}

// 连接字符串
void strcat(char dst[], char src[])
{
    int i, j;
    i = j = 0;
    while (dst[i] != '\0')
        i++;

    while ((dst[i++] = src[j++]) != '\0') // ++ 简化代码
        ;
}

// 删除字符串中所有指定的字符
// 思路：快指针向后遍历找其他字符填充到慢指针上，最后 '\0' 切断即可
void squeeze(char s[], char c)
{
    int i, j;
    for (i = j = 0; s[j] != '\0'; j++)
        if (s[j] != c)
            s[i++] = s[j]; // 非 c 字符则拷贝

    s[i] = '\0';
}
