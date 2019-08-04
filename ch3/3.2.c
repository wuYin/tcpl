#include <stdio.h>

void escape(char dst[], char src[]);
void unescape(char dst[], char src[]);

main()
{
    char s[] = "AB\tCD\nE";
    printf("[origin] |%s|", s);
    printf("\n\n");

    char t[10];
    escape(t, s);
    printf("[escaped] |%s|", t);
    printf("\n\n");

    char v[10];
    unescape(v, t);
    printf("[unescaped] |%s|", v);
    printf("\n\n");
}

// 复制字符串的函数将 '\n' 和 '\t' 可视化
void escape(char dst[], char src[])
{
    int i, j;
    j = 0;
    for (i = 0; src[i] != '\0'; i++)
        switch (src[i])
        {
        case '\t':
            dst[j++] = '\\';
            dst[j++] = 't';
            break;
        case '\n':
            dst[j++] = '\\';
            dst[j++] = 'n';
            break;
        default:
            dst[j++] = src[i];
            break;
        }

    dst[j] = '\0'; // 手动终结字符串
}

// 反向标识
void unescape(char dst[], char src[])
{
    int i, j;
    j = 0;
    for (i = 0; src[i] != '\0'; i++)
    {
        if (src[i] != '\\')
        {
            dst[j++] = src[i];
            continue;
        }

        if (src[i + 1] == '\0')
        {
            dst[j++] = '\\';
            break;
        }

        switch (src[i + 1])
        {
        case 'n':
            dst[j++] = '\n';
            i++;
            break;
        case 't':
            dst[j++] = '\t';
            i++;
            break;
        }
    }

    dst[j] = '\0';
}