#include <stdio.h>
#include <string.h>

int trim(char s[]);

// 3.7 break 语句与 continue 语句
main()
{
    char s[] = "demo \n\t ";
    int n = trim(s);
    printf("%d :%s:\n", n, s);
}

// 删除右侧空白符
int trim(char s[])
{
    int i;
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
            break;
    }

    s[i + 1] = '\0';
    return i;
}