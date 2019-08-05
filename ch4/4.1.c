#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);
int strrrindex(char s[], char t[]);

main()
{
    char s[] = "abcdecdz0";
    char t[] = "cd";
    printf("%d\n", strrindex(s, t));  // 5
    printf("%d\n", strrrindex(s, t)); // 5
}

// 返回字符串 t 在 s 中最右边出现的位置
// 思路：reverse 版本的 strindex
int strrindex(char s[], char t[])
{
    int i, j, k;
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        for (j = i, k = strlen(t) - 1; k >= 0 && j >= 0 && t[k] == s[j]; j--, k--)
            ;

        if (k == -1)
            return j + 1;
    }
    return -1;
}

// 直观上返回最后一次 strindex 的索引即可
// 高效简单：i 从 strlen(s)-strlen(t) 向前遍历，j/k 向后遍历对比
int strrrindex(char s[], char t[])
{
    int i, j, k;
    for (i = strlen(s) - strlen(t); i >= 0; i--) // 反向遍历
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}