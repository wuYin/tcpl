#include <stdio.h>
#include <math.h>

void itoa(char s[], int n);

// 实现递归的 itoa
main()
{
    int n = -12345;
    char s[10];
    itoa(s, n);
    printf("%s\n", s); // -12345
}

void itoa(char s[], int n)
{
    static int i;
    if (n / 10)
        itoa(s, n / 10); //
    else                 // 个位数
    {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }

    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0'; // 会被上次递归调用覆盖
}