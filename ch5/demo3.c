#include <stdio.h>

// 5.3 指针与数组
main()
{
    // C 指针能运算
    int a[] = {0, 1, 2, 3, 4, 5};
    printf("%p, %p\n", a, &a[0]);       // 同一内存地址 0x7ffeedfd37a0    // 数组名等价于 &a[0]
    printf("%p, %p\n", a + 1, &a[1]);   // 0x7ffeedfd37a4               // a+i  等价于 &a[i]
    printf("%d, %d\n", a[1], *(a + 1)); // 1

    // 数组名与指针的不同之处：数组名不是变量，不能进行赋值和参与运算
    // a++; // cannot increment value of type 'int [6]'

	char s[] = "c best";
	printf("%d, %d\n", strlen(s), strlen(&s[2])); // 6, 4 // 指针参数可传递子数组

	int nums[10];
	nums[-1] = -1;
	printf("%d\n", nums[-1]); // -1 只要确信元素存在，可引用 0 之前的元素
}

// 数组传参即传首元素地址
// char s[] 与 char *s 等价
int strlen(char *s)
{
	int n;
	for (n = 0; *s != '\0'; s++) // C 函数只传值，s 是指针副本，运算后不影响调用方的 s
		n++;
	return n;
}