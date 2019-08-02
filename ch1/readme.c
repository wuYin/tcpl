#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char *concat(const char *s1, const char *s2);
int sum(int, int);

main()
{
    char *s = concat("hello, ", "world");
    printf("%s\n", s);
    free(s); // 调用方需手动释放

    printf(":%6.1f:\n", 1.55); // :   1.6:
    printf("%.0f\n", 1.55);    // 2

    printf("EOF: %d\n", EOF); // -1

    printf("sum: %d\n", sum(1, 2)); // 3

    char *str = "ab";
    int i = 0;
    while (str[i])
        printf("%c\n", str[i++]);
}

char *concat(const char *s1, const char *s2)
{
    // char *s = malloc(strlen(s1) + strlen(s2) + 1); // +1 是 '\0'
    // if (s == NULL)                                 // 分配失败
    //     exit(1);

    // strcpy(s, s1); // 拷贝
    // strcat(s, s2); // 连接
    // return s;

    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *s = malloc(len1 + len2 + 1); // +1 是 '\0'
    if (s == NULL)                     // 分配失败
        exit(1);

    memcpy(s, s1, len1);
    memcpy(s + len1, s2, len2 + 1); // [0...len1-1] + [len1... len2-1] + ['\0]
    return s;
}

int sum(x, y)
{
    return x + y;
}