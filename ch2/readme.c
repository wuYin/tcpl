#include <stdio.h>

main()
{
    char str[] = "hello, " // 编译时连接，必须是字符串常量
                 "world"
                 "\n";
    printf("%s", str);

    printf("%d\n", (int)1.5);          // 1
    printf("%f\n", (float)1.55555555); // 1.555556

    char s[] = "hello";
    int i = 0;
    while (s[i++] != '\0')
        ;
    printf("%d\n", i); // 6 // not ok
}