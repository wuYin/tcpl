#include <stdio.h>

int strend(char *s, char *t);

main()
{
    printf("%d\n", strend("demo", "x"));
}

// 检查 t 是否出现在 s 尾部
// 指针自减运算
int strend(char *s, char *t)
{
    char *sHead = s;
    char *tHead = t;

    while (*s)
        s++;
    while (*t)
        t++;

    for (; t >= tHead && s >= sHead && *s == *t; t--, s--)
        ;

    t++;
    if (t == tHead)
        return 1;

    return 0;
}