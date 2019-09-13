## 第 6 章：结构

介绍 C 中 struct 结构的概念，结构指针，typedef 和 union

### 6.1 结构基本概念

struct 声明的结构名可有可无，定义新的数据类型。

### 6.2 结构和函数

C 中函数传参只有值传递，所以传结构时会完整拷贝副本低效，一般传指针。不过注意结构指针不会自动解引用：

```c
struct point p = {1, 1};
struct point *pp = &p;
printf("%d %d", (*pp).x, pp->y); // 1 1 // 省略括号后 *pp.x，表示取成员 x 指针的值
```

|          运算符           |  结合性  |
| :-----------------------: | :------: |
|       `() [] -> .`        | 从左至右 |
| `++ -- * & (type) sizeof` | 从右至左 |

### 6.3 结构数组

全局数组的长度在编译期间确定，故可手动计算：

```c
struct key {
	char *word;
	int count;
} keytab[] = {
		{"for", 0},
		"break", 0,
};

#define NKEYS (sizeof keytab / sizeof (struct key)) // 2 
#define NKEYS (sizeof keytab / sizeof keytab[0])    // 2
```

### 6.4 指向结构的指针

注意内存对齐。

### 6.5 自引用

struct 不能递归包含自身实例，但可以包含指向其的指针：

```c
struct x {
	struct x y;  // error:  field has incomplete type 'struct x'
	struct x *z; // ok // int 值的数据不冲突
};
```

### 6.8 联合

union 可简单理解为多类型动态变量。