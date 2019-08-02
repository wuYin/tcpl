#include <stdio.h>

// 1.6 数组
main()
{
    // 统计输入中数字、空白符和其他字符出现的次数
    int c, i, nwhite, nother;
    int ndigits[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++) // 数组显式初始化
        ndigits[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ndigits[c - '0']++;
        else if (c == ' ' || c == '\t' || c == '\n')
            nwhite++;
        else
            nother++;

    printf("digits: ");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigits[i]);
    printf(", white: %d, other:%d\n", nwhite, nother);
}