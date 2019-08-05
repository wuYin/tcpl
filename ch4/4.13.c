#include <stdio.h>
#include <string.h>

void reverse(char s[]);

// 递归实现字符串逆序
main()
{
    char s[] = "demo";
    reverse(s);
    printf("%s\n", s);
}

void reverse(char s[])
{
    void rev(char s[], int l, int r);
    rev(s, 0, strlen(s) - 1);
}

void rev(char s[], int l, int r)
{
    if (l < r)
    {
        int c = s[l];
        s[l] = s[r];
        s[r] = c;
        rev(s, l + 1, r - 1);
    }
}