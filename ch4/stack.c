#include <stdio.h>
#include "calc.h"

extern int next;
extern int stack[];
// extern MAX_ELEMS; // 宏不是全局变量，不能使用 extern 关键字声明。
// 若多个 *.c 文件要共享则集中放入头文件 *.h

// 栈操作相关
// 压入栈
void push(double f)
{
    if (next < MAX_ELEMS)
        stack[next++] = f;
    else
        printf("push: stack full\n");
}

// 弹出栈
double pop()
{
    if (next > 0)
        return stack[--next];

    printf("pop: stack empty\n");
    return 0.0;
}