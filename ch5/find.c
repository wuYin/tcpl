#include <stdio.h>
#include <string.h>
#include "ch5.h"

// 在输入中查找匹配命令行参数的行
// 带 -x 排除匹配行、-n 打印行号功能
int main(int argc, char *argv[])
{
    int c, except = 0, number = 0, found = 0; // 字符型、布尔型、整型...

    // 命令行参数的标记
    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("invalid command flag");
                exit(-1);
            }
    }

    int lineno;
    char line[1000];
    while (getLine(line, 1000) > 0)
    {
        lineno++;
        // 无 -x 不匹配要排除
        // 有 -x 不匹配但不排除，即匹配要排除
        if ((strstr(line, *argv) != NULL) != except) // 十分精妙....
        {
            if (number)
                printf("%ld: ", lineno);
            printf("%s", line);
            found++;
        }
    }

    return found;
}
