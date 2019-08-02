#include <stdio.h>

#define IN 1  // 构建新单词中
#define OUT 0 // 在单词外

void cp1();
void cp2();
void cc1();
void cc2();
void lc();
void wc();

// 1.5 字符输入与输出
main()
{
    // 1.5.1 文件复制
    // cp1();
    // cp2();

    // 1.5.2 字符计数
    // cc1();
    // cc2();

    // 1.5.3 行计数
    // lc();

    // 1.5.4 单词计数
    wc();
}

// 统计单词数
// 思路：读取字符时标记当前状态是否正在构建新单词
void wc()
{
    int c, nl, nw, nc, state;
    nl = nw = nc = 0; // 连续赋值从右自左求值并赋值
    state = OUT;      // 显式初始化为未在单词外，否则值是栈上的旧未知值

    while ((c = getchar()) != EOF)
    {
        nc++;
        if (c == '\n')
            nl++;
        if (c == '\n' || c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }

    printf("char: %d, word:%d, line:%d\n", nc, nw, nl);
}

// 统计行数
void lc()
{
    int c, ln;
    ln = 0;
    while ((c = getchar()) != EOF)
        // if (c = '\n') // 踩坑：'\n' != '\0' 故表达式的值为 1，始终为真
        if (c == '\n')
            ++ln;
    printf("line count: %d\n", ln);
}

// 改进：统计更多字符
void cc2()
{
    double nc;
    for (nc = 0; getchar() != EOF; nc++)
        ;                             // 空语句独占一行 bingo
    printf("char count: %.0f\n", nc); // %.0f 强制不打印小数部分（%d 也不会舍入后输出，结果是未知的，参数和类型标记必须匹配）
}

// 统计字符数
void cc1()
{
    long nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("char count: %ld\n", nc); // ld 标记 long int
}

// 将输入复制到输出
void cp1()
{
    int c;
    c = getchar();
    // while (c != EOF)
    while (c != -1) // EOF 是 -1 的符号常量
    {
        putchar(c);
        c = getchar();
    }
}

// 优化：适当精简代码
// 赋值表达式的值就是所赋的值
void cp2()
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}