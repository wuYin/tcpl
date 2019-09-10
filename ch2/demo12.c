#include <stdio.h>

// 1.12 运算符优先级与求值顺序
main() {
	int nums[] = {10, 20, 30};
	int i = 1;
	nums[i++] = i;

	for (int j = 0; j < 3; j++)
		printf(" %d ", nums[j]); // [10, 1, 30]

	printf("\n i:%d\n", i); // 2

	// ++ 和 -- 对参数的副作用必须在函数调用前生效
	int x = 1;
	int y = 10;
	printf("sum: %d\n", sum(x++, ++y)); // 12
	printf("x:%d, y:%d\n", x, y);       // 2 11
}

int sum(int x, int y) {
	return x + y;
}