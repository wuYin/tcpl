#include <stdio.h>
#include <ctype.h> // 与字符集无关的检测与转换函数

int atoi(char s[]);
char lower(char c);

main()
{
    printf("atoi: %d\n", atoi("100")); // 100
    printf("lower: %c\n", lower('A')); // a

    printf("tolower: %c, %c\n", tolower('C'), tolower('1')); // c, 1
    printf("isdigit: %d, %d\n", isdigit('4'), isdigit('A')); // 1, 0

    // int 转为 char 时，超出的高位将被丢弃
    int n = 258;
    char c = n;
    printf("c: %d\n", c); // 2

    float f = 1.5;
    printf("n: %d\n", (n = f)); // 1 // 浮点数转 int 直接截断小数不进位
    double d = 1.5555555555;
    printf("f: %f\n", (f = d)); // 1.555556 // double 转 float 不截断会进位
}

// 将字符转换为小写字母
char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}

// 将数字字符串转换为数字
int atoi(char s[])
{
    int res = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        res = res * 10 + s[i] - '0';

    return res;
}
