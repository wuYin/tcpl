#include <stdio.h>

#define MAX_LINE 1000

char parttern[] = "ould";

// 4.1 函数的基本知识
// cc main.c getline.c strindex.c
// 编译三个源文件生成对应 *.o 并加载至 a.out 可执行文件中
main()
{
    char line[MAX_LINE];
    int found;
    while (getLine(line, MAX_LINE) > 0)
        if (strindex(line, parttern) >= 0)
        {

            printf("%s", line);
            found++;
        }

    return found;
}
