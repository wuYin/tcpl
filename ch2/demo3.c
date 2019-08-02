#include <stdio.h>

int strlen(char s[]);

// 2.3 常量
main()
{
    printf("NUL: %d\n", '\0'); // 0  // 空字符 NULL 的 ASCII 编码为 0
    printf("0: %d\n", '0');    // 48 // 字符 0 编码为 48

    // 编译时可将多个字符串常量连接起来
    char *s = "hello"
              " "
              "world";
    printf("concat by string literals: %s\n", s); // 还有这种操作...

    printf("strlen: %d\n", strlen("demo")); // 4

    enum NUMBER
    {
        zero, // 从 0 自动生成整型常量值
        one = 2,
        two,
    };
    printf("zero: %d, two: %d\n", zero, two); // 0 3
}

// 扫描字符数组返回字符串长度
int strlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}