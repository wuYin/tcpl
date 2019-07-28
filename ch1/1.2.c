#include <stdio.h>

main()
{
	printf("n: \n");
	printf("t1\tt2 \n");
	printf("\"     \n");
	printf("\\     \n");
	printf("c: \c  \n");
	printf(" b-\b    ");

	// n:q
	// t1	t2
	// "
	// \
	// c: c   // \c is not a valid
	//  b     // 退格即删除一个字符
}