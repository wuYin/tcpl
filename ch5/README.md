## 第 5 章：指针与数组

介绍指针概念，指针与数组间的等价计算，指针本身的运算，指向指针的指针，读取命令行参数，及指向函数的指针等。

### 5.1 指针与地址

& 只能取内存中的对象如变量、数组元素，像 register 变量、常量是不能取地址的：

```c
#define MAX_LINE 100
main() {
    int *ip = &MAX_LINE; // error: cannot take the address of an rvalue of type 'int'
}
```

误： `int *p` 不是指变量 p 是 `int *` 类型，而是声明指针变量 p 取值的结果 *p 是 int 类型。

注意：* 寻址符与 ++, -- 等自增自减运算符优先级相同，均为第 2 级，但结合顺序是从右向左的。

### 5.2 指针与函数参数

C 中的函数传址实际上是传指针值，只不过函数内部能访问和修改调用方指针指向对象的值。

### 5.3 指针与数组

- 数组名即指向数组首元素的指针
- 数组下标表达式能用指针加偏移量等价实现：`a[i] == *(a+i)`，即 `&a[i] == a+i`，其中偏移单位是对象，而非字节。

```c
main() {
    char s[] = "demo";
    printf("%p, %p", s, &s[0]);       // 0x7ffee5dad7bb, 0x7ffee5dad7bb
    printf("%c, %c", s[2], *(s + 2)); // m, m
}
```

注意 0 永远是无效指针，即 `NULL`



### 5.4 地址运算符

NULL 即空指针，其数值为 0，与 `'\0'` 和 0 均相等：

```c
printf("%d, %d", NULL == 0, NULL == '\0'); // 1 1
```

合法的指针变量间的运算包括：

- 同类型指针的赋值：`int *p1, *p2; p1 = p2;`

- 指针与整数的加减法：`int *s = "abc"; s++; s--;`

- 指向相同数组元素指针间的减法，比较：

  ```c
  char *s = "abcd";
  char *p1 = s;
  char *p2 = s + 3;
  printf("%d, %d\n", p1 == p2, p2 - p1); // 0 3
  ```

- 将指针赋值为 `NULL`，与 `NULL` 的比较运算。



### 5.5 字符指针与函数

注意区分字符串的两种声明方式：

```c
char p1[] = "abcd"; // p1 指向字符数组首元素的地址，可修改元素值
char *p2 = "abcd";  // p2 指向字符串常量，不能修改元素值

// p1 = p2;     // 字符数组的数组名不是变量，不能赋值 // error: array type 'char [5]' is not assignable
// p2[1] = 'x'; // 字符指针指向内存中的字符串常量，其值无法修改
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

```c

int sum(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

main() {
	// 函数指针变量
	int (*calc)(int, int); // 与 int *calc  不同，其括号表明 calc 是函数指针
	calc = &sum;
	printf("%d\n", calc(1, 1)); // 2
	calc = sub;                 // 和数组首元素类似，对于函数 “取地址” 可省略 &
	printf("%d\n", calc(1, 1)); // 0

	// 函数指针类型
	typedef int (*TCalc)(int, int);
	TCalc f = sum;
	printf("%d\n", f(1, 1)); // 2
}
```

### 5.12 复杂声明

```c
char **argv;  // 指向字符指针的指针
int (*p)[3];  // 指向长度为 3 的 int 数组 // 相当于指向数组首元素的指针的指针
int *p[3];    // 保存 3 个 int 指针的数组
void *f();    // 函数返回 void* 的返回值
void (*f)();  // f 是指向返回 void 的函数的指针

// ... 迷惑鉴赏大赛 ...
```

