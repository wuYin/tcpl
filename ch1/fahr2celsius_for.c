#include <stdio.h>

// 打印华氏温度到摄氏温度对照表
main() {
	int f;
	for (f = 0; f <=300; f+=20) {
		printf("%3d %6.1f\n", f, (5.0/9.0)*(f-32));
	}
}