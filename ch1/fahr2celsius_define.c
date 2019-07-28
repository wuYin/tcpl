#include <stdio.h>

// 定义符号常量
#define LOWER 0 
#define UPPER 300
#define STEP  20

main() {
	int f;
	for (f=LOWER; f<=UPPER; f+=STEP) {
		printf("%3d %6.1f\n", f, (5.0/9.0)*(f-32));
	}
}