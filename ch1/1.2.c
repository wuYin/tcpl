#include <stdio.h>

// 试试打印非标准转义字符
main() {
	printf("n: \n");
	printf("t1\tt2 \n");
	printf("\"     \n");
	printf("\\     \n");
	printf("abc\b  \n"); //
	printf("\7");        // ASCII 的 7 BEL 蜂鸣声
	printf("\xA");       // LF 换行键 '\0' 也会发出蜂鸣声

	// n:
	// t1	t2
	// "
	// \
	// ab     // 退格即删除一个字符 c
}