#include <stdio.h>

int htoi(char s[]);
int power(int x, int n);

// 将十六进制字符串转为整型数字
main()
{
    printf("%d\n", htoi("0X0011"));
}

// 从后向前逐个乘 16 的 l-1-i 次方
int htoi(char s[])
{
    int l = strlen(s);
    int lim = 0;
    if (l >= 2 && s[0] == '0' && (s[1] == 'x') || s[1] == 'X')
        lim = 1;

    int res = 0;
    for (int i = l - 1; i > lim; i--)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            res += (s[i] - 'a') * power(16, l - 1 - i);
        else if (s[i] >= 'A' && s[i] <= 'Z')
            res += (s[i] - 'a') * power(16, l - 1 - i);
        else if (s[i] >= '0' && s[i] <= '9')
            res += (s[i] - '0') * power(16, l - 1 - i);
        else
            return 0;
    }

    return res;
}

int power(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        res *= x;
        n--;
    }
    return res;
}

int strlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
