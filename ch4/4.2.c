#include <stdio.h>

double atof(char s[]);

// 扩展 atof 能处理科学计数法：x-ey 或 x-Ey
main()
{
    printf("atof: %f\n", atof(" -4E-2")); // -0.040000
}

// 继续处理 e/E 后续部分
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
    res = sign * res / power;

    // 扩展处理指数部分
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        sign = s[i] == '-' ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;

        int exponent = 0;
        for (; isdigit(s[i]); i++)
            exponent = exponent * 10 + (s[i] - '0');

        if (sign == 1)
            while (exponent-- > 0)
                res *= 10;
        else
            while (exponent-- > 0)
                res /= 10.0;
    }

    return res;
}