## 第 5 章：指针与数组

### 5.1 指针与地址

& 只能取内存中的对象如变量、数组元素，像 register 变量、常量是不能取地址的：

```c
#define MAX_LINE 100
main() {
    int *ip = &MAX_LINE; // error: cannot take the address of an rvalue of type 'int'
}
```

### 5.2 指针与函数参数

C 中的函数传址实际上是传指针值，函数内部能访问和修改调用方指针指向对象的值。

### 5.3 指针与数组

- 数组名即指向数组首元素的指针
- 数组下标表达式能用指针加偏移量等价实现：`a[i] == *(a+i)`，即 `&a[i] == a+i`

```c
main() {
    char s[] = "demo";
    printf("%p, %p", s, &s[0]);       // 0x7ffee5dad7bb, 0x7ffee5dad7bb
    printf("%c, %c", s[2], *(s + 2)); // m, m
}
```

### 5.4 地址运算符

NULL 即空指针，其数值为 0，与 `'\0'` 和 0 均相等：

```c
printf("%d, %d", NULL == 0, NULL == '\0'); // 1 1
```

注意 `*` 与 `++`、`—` 等一元运算符优先级相等，但结合方向是从右到左，注意使用 () 分割。

### 5.5 字符指针与函数

注意区分：

```c
char p1[] = "abcd"; // p1 指向字符数组首元素的地址，可修改元素值
char *p2 = "abcd";  // p2 指向字符串常量，不能修改元素值
```

### 5.6 指针数组与指向指针的指针

### 5.7 多维数组

将多维数组作为参数传递给函数时，列数是必需的：

```c
// void up(int twice[][])   // error: array has incomplete element type 'int []'
// void up(int twice[2][2]) // ok
// void up(int twice[][2])  // ok
void up(int (*twice)[2])    // ok  // 声明时，int *twice 与 int twice[] 等价，注意 [] 优先级更高
{
    twice[0][0]++;
    twice[1][1]++;
}
```

### 5.8 指针数组的初始化

常用于 `char *s[]` 指向不同长度的字符串，是相比二维字符数组的优势。

### 5.9 指针与多维数组

### 5.10 命令行参数

```c
printf("%d", argv[argc] == NULL); // 1
```

### 5.11 指向函数的指针

### 5.12 复杂声明