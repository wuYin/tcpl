## 第 4 章：函数与程序结构

### 4.1 函数的基本知识

函数间交换值方式：参数传递、返回调用结果、共享全局变量。

### 4.2 返回非整型值的函数

函数原型与函数实现在同一文件中时，编译器能检查类型类型不一致的错误。但当分开到不同文件时：

```c
// readme.c
double sum(double x, double y)
{
    return x + y;
}
```

```c
// readme_2.c
#include <stdio.h>

int sum(int x, int y);

int main()
{
    int x = 1, y = 2;
    printf("sum: %d\n", sum(x, y)); // 结果无效
}
```

先将 readme.c 只编译不链接，再链接执行时编译器不检查类型不一致的错误：

 <img src="https://images.yinzige.com/2019-08-05-070218.png" width=60% />



### 4.3 外部变量

场景：两个函数不会相互调用，但又需共享某些数据，可将其定义为全局变量。



### 4.4 作用域规则

在 `main()` 前声明函数原型的原因：全局变量和函数的作用域是从定义到文件结尾，函数实现对 main 不可见。

`extern` 仅做声明之用，不分配内存。但不能声明使用 static 静态变量，如：

```c
// readme.c
static char *name = "Dennis";

// readme_2.c
extern char *name;
```

编译出错：

 ![image-20190805151219574](https://images.yinzige.com/2019-08-05-071220.png)



### 4.5 头文件

`*.h` 头文件保存多个 `*.c` 中需共享的符号常量、宏定义、函数原型声明。如计算器程序中符号常量 `NUMBER_FLAG` 在 main.c 和 getop.c 中均有使用，将其写入 calc.h 中，二者 `include "calc.h"` 即可。



### 4.6 静态变量

static 标识的全局变量、函数都只能在其定义的文件中使用。static 也可用于局部变量，变量只能在函数内使用，但其不跟随函数调用生命周期进行初始化和销毁：

```c
main() {
    for (int i = 0; i < 3; i++)
        incr1(), incr2();
}

void incr1() {
    static int n = 1;
    printf("incr1: %d\n", n++); // 1 2 3
}

void incr2() {
    int n = 1;
    printf("incr2: %d\n", n++); // 1 1 1
}

```



### 4.7 寄存器变量

register 变量的地址无法访问。



### 4.8 程序块结构

### 4.9 初始化

### 4.10 递归

### 4.11 C 预处理器

较长的宏定义可用 `'\'` 换行定义，如：

```c
#define MAX(A, B) ((A) > (B)) \
                      ? (A)   \
                      : (B)
```

注意宏的本质是纯粹的文本 “替换”，需使用圆括号来保证计算次序：

```c
// not ok
#define square(x) x *x
int z = 2;
printf("%d", square(z + 1)); // 5 // 2+1*2+1 = 5 

// ok
#undef square
#define square(x) (x) * (x) // 9 // (2+1)*(2+1) = 9
```