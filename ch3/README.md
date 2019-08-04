## 第3章 控制流

#### 3.1 语句与程序块

```c
{} // 一对花括号即是一个范围独立的代码块
```

### 3.2 if-else语句

else 与向上最近未配对的 if 配对。

### 3.3 else-if语句

if-else 与 else-if 常用于多路条件判断场景。

### 3.4 switch语句

C 中的 switch 只能用于 integer 整数值常量的多路判断。默认 fallthrough 需手动 break 跳出判断。

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

### 3.6 do-while循环

至少执行一次循环体。

### 3.7 break语句与continue语句

### 3.8 goto语句与标号

可用在一次跳出深层嵌套的 for 循环而不用一层层 break，尽量少用避免代码流程满天飞，可阅读性低。