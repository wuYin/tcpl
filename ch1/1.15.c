#include <stdio.h>

float conv(int f);

main()
{
	int f;
	for (f = 0; f <= 300; f += 20)
	{
		printf("%3d %4.1f\n", f, conv(f));
	}
	return 0;
}

float conv(int f)
{
	return (5.0 / 9.0) * (f - 32);
}

// Go -> C
// 1. 语句或表达式不要忘记加分号。
// 2. 声明变量时类型放在前边。