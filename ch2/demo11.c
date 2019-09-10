#include <stdio.h>

// 定义宏
#define MAX(a, b) (a > b) ? (a) : (b)

// 2.11 条件表达式，即三元运算符
main() {
	printf("%d\n", MAX(1, 2)); // 2

	// 每行打印 3 个元素
	int nums[7] = {1, 2, 3, 5, 6, 7};
	for (int i = 0; i < 7; ++i) {
		printf("%3d %c", nums[i], (i % 3 == 2 || i == 7 - 1) ? '\n' : ' ');
	}
}