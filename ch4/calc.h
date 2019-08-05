// 头文件中存放各子程序模块需共享的全局变量和宏

#define NUMBER_FLAG '0'
#define MAX_ELEMS 100 // 栈最多 100 个元素

int getch(void);
void ungetch(char c);
int getop(char s[]);
void push(double f);
double pop();