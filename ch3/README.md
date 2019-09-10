## 第3章 控制流

介绍 C 的控制流语句：if-else, else-if 条件判断, switch 多路判定，for, while, do-while 循环，break 和 contine 以及 goto 语句。

#### 3.1 语句与程序块

表达式加 `;`  即语句。

```c
{} // 一对花括号即是一个范围独立的代码块
```

### 3.2 if-else语句

else 与向上最近未配对的 if 配对，注意缩进格式化，或直接使用 `{}` 

### 3.3 else-if语句

if-else 与 else-if 常用于多路条件判断场景。

### 3.4 switch语句

C 中的 switch 只能用于整数值常量的多路判断，默认是 fallthrough 需手动 break 跳出判断。

```c
main()
{
    float f = 2.1;
    switch(f){    // statement requires expression of integer type ('float' invalid)
        case 2.1: // expression is not an integer constant expression
    }
}
```

### 3.5 while循环与for循环

C 中 for 语句的初始化可以像 Go 一样同时声明并初始化多个变量，但类型需一致：

```c
// ok
for (int i = 1, j = 5; i < j; i++, j--)
        printf("%d+%d = 6\n", i, j); // 1+5 = 6  // 2+4 = 6

// also ok
for (float i = 1, j = 5; i < j; i++, j--)
        printf("%.0f+%.0f = 6\n", i, j); // 1+5 = 6  // 2+4 = 6

// not ok
for (int i = 1, short j = 5; i < j; i++, j--) // expected identifier or '('
    printf("%d+%d = 6\n", i, j);
```

原因：C 中的优先级最低的逗号运算符 `,` 分隔的是表达式，而 `short j = 5;` 是声明语句。

建议：

- 无初始化或重新初始化的循环，使用 `while` 
- 需初始化和递增减变量，使用 `for`

### 3.6 do-while循环

用于至少执行一次循环体的场景。

### 3.7 break语句与continue语句

break 能从 for, while, do-while 的最内层循环，switch  语句中跳出。

### 3.8 goto语句与标号

可用在一次跳出深层嵌套的 for 循环而不用一层层 break，尽量少用避免代码流程满天飞，可阅读性低。

LABEL 标号的作用域是函数，goto 语句必须与 LABEL 在同一函数内才能跳转：`error: use of undeclared label 'LABEL'`