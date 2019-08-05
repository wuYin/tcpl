#include <stdio.h>

int getLine(char *s, int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) && c != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
    return i;
}
