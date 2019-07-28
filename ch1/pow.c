#include <stdio.h>

// 函数原型
// 下方实现的定义和用法必须一致
int power(int base, int n); // 参数名可选，就 define 无需加分号...

main() {
	int i;

	for (i=0; i<10; i++) {
		printf("%d\t%d\t%d\n", i, power(2,i), power(-3,i));
	}
	return 0;
}


int power(int base, int n) {
	int i, res;
	res = 1;

	for (i=0; i<n; i++) {
		res *= base;
	}
	return res;
}