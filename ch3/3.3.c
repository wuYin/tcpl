#include <stdio.h>

void expand(char s1[], char s2[]);

main()
{
    char s1[] = "1-9_a-z";
    char s2[100];
    expand(s1, s2);
    printf("s2: %s\n", s2); // 123456789_aabcdefghijklmnopqrstuvwxyz
}

// 将 s1 中的速记写法 a-z 展开到 s2 中
void expand(char s1[], char s2[])
{
    int c, i, j;
    i = j = 0;
    while ((c = s1[i++]) != '\0')
    {
        if (s1[i] == '-' && c < s1[i + 1]) // - 分割的速记字符区间
        {
            i++;
            while (c <= s1[i])
                s2[j++] = c++; // 扩展
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
}