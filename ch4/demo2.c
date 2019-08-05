#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

// 4.2 返回非整型值的函数
// cc demo2.c getline.c
// ./a.out
main()
{
    // 简单的求和计算器
    double sum, atof(char s[]);
    char line[1000];
    int getLine(char line[], int max);

    sum = 0;
    while (getLine(line, 1000) > 0)
        sum += atof(line);

    printf("sum: %f\n", sum);

    // char *s[] = {"0.1", " .1", "1. ", ".12", "12.", "-1."};
    // for (int i = 0; i < 6; i++)
    // printf("%s = %.2f\n", s[i], atof(s[i]));
}

// 字符串转浮点数
double atof(char s[])
{
    int i, sign, power;
    double res;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;

    for (res = 0.0; isdigit(s[i]); i++)
        res = res * 10.0 + (s[i] - '0');

    if (s[i] == '.')
        i++;
    for (power = 1; isdigit(s[i]); i++)
    {
        res = res * 10.0 + (s[i] - '0');
        power *= 10;
    }

    return sign * res / power;
}

// 若被调用的函数在其他源文件中，本文件中错误使用了其返回值类型
// 编译器不会检查此类错误，返回的值将是无效的