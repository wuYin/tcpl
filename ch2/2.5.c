#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
    printf("any: %d\n", any("abcd", "control")); // 2
}

// s2 中任意字符在 s1 中出现的位置
// 思路：直接双重遍历即可
int any(char s1[], char s2[])
{
    int i, j;
    for (j = 0; s2[j] != '\0'; j++)
        for (i = 0; s1[i] != '\0'; i++)
            if (s2[j] == s1[i])
                return i;

    return -1;
}