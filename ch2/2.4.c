#include <stdio.h>
void squeeze(char s1[], char s2[]);

main()
{
    char s[] = "hello, world";
    squeeze(s, "lo");
    printf(":%s:\n", s); // :he, wrd:
}

// 将 s1 中所有在 s2 中出现过的字符删除
// 思路：对 s1 还是快慢指针的操作，但快指针需逐一与 s2 对比所有字符，若均不相等则 s2 会遍历到尾部 '\0'，借助 s2 遍历结果判断即可
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[j] != '\0'; j++)
    {

        for (k = 0; s2[k] != '\0' && s2[k] != s1[j]; k++)
            ;
        if (s2[k] == '\0') // s1[j] 与 s2 任一字符均不重复
            s1[i++] = s1[j];
    }

    s1[i] = '\0';
}
