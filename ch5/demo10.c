#include <stdio.h>
#include <string.h>
#include "ch5.h"

// 5.10 命令行参数
main(int argc, char *argv[])
{
    // return echo2(argc, argv);

    // 在输入中查找命令行参数指定的模式串
    int found;
    if (argc != 2)
    {
        printf("useage: ./a.out pattern");
        return -1;
    }

    char line[1000];
    while (getLine(line, 1000) > 0)
        if (strstr(line, argv[1]) != NULL)
        {
            printf("%s", line);
            found++;
        }

    return found;
}

// 递减 argc 和自增 argv 指针
int echo2(int argc, char *argv[])
{
    while (--argc > 0)
        printf("%s ", *++argv); // 跳过 argv[0] 程序名
    printf("\n");
    return 0;
}

// 直接输入命令行参数
int echo1(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; i++)
        printf("%s ", argv[i]);
    printf("\n");
    return 0;
}