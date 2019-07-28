#include <stdio.h>

main() {
	int c, nl;

	// 全局变量和静态变量声明后值为零值
	// 局部变量声明后值为栈内存上的脏数据，即随机数
	nl = 0;
	while((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		}
	}

	printf("%d\n", nl);
}