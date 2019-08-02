#include <stdio.h>

// 将文本中出现的制表符 \t 替换为适当的空格，假设场景是表格
// 假定 tab == 8*space
main()
{
    int c, space, count;
    count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            // 计算需多少个空格来填充完当前的 tab
            space = 8 - count % 8;
            while (space > 0)
            {
                putchar(' ');
                space--;
                count++;
            }
        }
        else if (c == '\n')
        {
            putchar('\n');
            count = 0; // 归零重新计数
        }
        else
        {
            putchar(c); // 正常字符则输出
            count++;
        }
    }
}