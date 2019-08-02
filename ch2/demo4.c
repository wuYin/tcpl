#include <stdio.h>

int ext;
static int st1;

int trimTail(const char s[]);

// 2.4 声明
main()
{
    static int st2;                                                     // 全局变量和 static 声明时会被默认初始化为 0
    int loc;                                                            // 局部变量初始化的值是栈上未知的旧值
    printf("extern: %d, static:%d,%d, local:%d\n", ext, st1, st2, loc); // 0 0 0 1
}

// const 修饰的变量不能被修改，编译时检查
int trimTail(const char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    // if (i > 1)
    // s[--i] = '\0'; // 尝试修改 s // 编译错误 error: read-only variable is not assignable

    return i;
}