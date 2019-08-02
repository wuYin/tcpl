#include <stdio.h>

float conv(int f);

// 使用函数实现温度转换
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