#include <stdio.h>
#include <stdlib.h> // atof 函数
#include "calc.h"

#define MAX_EXP_LEN 100

int getop(char s[]);
void push(double f);
double pop();

// 4.3 外部变量 // 逆波兰计算器
// cc 4.3.c stack.c getop.c stack_elems.c getch.c && ./a.out
// 1 1 +
// 2
main()
{
    int flag;
    int a, b;
    char exp[MAX_EXP_LEN];
    while ((flag = getop(exp)) != EOF)
    {
        switch (flag)
        {
        case NUMBER_FLAG: // 数字则入栈
            push(atof(exp));
            // printf("atof(exp): %f\n", atof(exp));
            break;
        case '+':
            push(pop() + pop()); // + * 满足交换律
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            b = pop(); // 被减数先出栈
            a = pop();
            push(a - b);
        case '/':
            b = pop(); // 被除数先出栈
            if (b == 0.0)
            {
                printf("error: zero devide\n");
                exit(1);
            }
            a = pop();
            push(a / b);
            break;
        case '\n':
            printf("\n[result]: %.8g\n", pop());
            break;
        default:
            printf("unknown operator: %s\n", exp);
            break;
        }
    }

    return 0;
}
