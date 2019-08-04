#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

// 3.6 do-while 循环
main()
{
    char s[100];
    itoa(-12345, s);
    printf("itoa: %s\n", s); // -12345
}

// 将数字转换为字符串并保存在 s 中
// 使用 do-while 循环体至少被执行一次，当 n 为 0 需先执行
void itoa(int n, char s[])
{
    int sign, i;

    if ((sign = n) < 0) // 记录正负号
        n = -n;         // 使 n 成为正数

    i = 0;
    do // 反序生成数字
    {
        s[i++] = n % 10 + '0'; // 取下一个数字
    } while ((n /= 10) > 0);   // 删除该数字

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

// 反转字符串
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) // "," 逗号运算符从左到右求值，优先级最低
        c = s[i], s[i] = s[j], s[j] = c;            // 简化版的顺序赋值，一条语句实现 swap
}