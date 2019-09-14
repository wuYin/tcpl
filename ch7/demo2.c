#include <stdio.h>

// 7.2 格式化输出 printf 函数
int main() {
	int n = 100;
	printf("%p\n", &n); //输出 void * 指针类型

	double x = 1.256;
	printf("%.*f\n", 2, x); // 1.26 // 格式化表达式中的宽度或精度可用 * 对后续的整型值进行占位

	char *s = "hello, world";
	printf(":%s:\n", s);       // :hello, world:
	// 最小宽度
	printf(":%10s:\n", s);     // :hello, world:
	// 小数点指定最大精度
	printf(":%.10s:\n", s);    // :hello, wor:
	// 左对齐
	printf(":%-10s:\n", s);    // :hello, world:
	printf(":%.15s:\n", s);    // :hello, world:
	printf(":%-15s:\n", s);    // :hello, world   :

	// 默认右对齐，精度为 10，长度为 15 不够左侧空格补
	printf(":%15.10s:\n", s);  // :     hello, wor:
	n = printf(":%-15.10s:\n", s); // :hello, wor     :

	char *res = (char *) malloc(40);
	//res = sprintf(":%s:", s);
	printf("[res] %s\n", res);
}