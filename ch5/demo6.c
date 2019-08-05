#include <stdio.h>

// 5.6 指针数组与指向指针的指针
main()
{
    // 指针本身也是变量，可存放于数组中
    char *s[10] = {"abc", "def"};
    for (int i = 0; i < 2; i++)
        printf("%c\n", *s[i]); // a d
}