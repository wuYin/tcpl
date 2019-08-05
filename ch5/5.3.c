#include <stdio.h>

void strcat(char *s, char *t);

// 用指针实现 strcat
main()
{
    char s[] = "abc";
    char *t = "DEF";
    strcat(s, t);
    printf("%s\n", s); // abcDEF
}

void strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;

    *s = '\0';
}