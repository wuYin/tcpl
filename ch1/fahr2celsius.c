#include <stdio.h>


/* 
 * 当华氏温度 f=0,20...300时，分别
 * 打印华氏温度和摄氏温度的对照表
 */
main() {
	// int f, c;
	float f, c;
	int lower, upper, step;
 
	lower = 0;   // 华氏温度计下限
	upper = 300; // 上限
	step  = 20;  // 步长

	f = lower;
	while(f <= upper) {
		// c = (f-32)*5 / 9;
		// printf("%3d %6d\n", f, c);
		c = (f-32.0)*5.0 / 9.0;
		printf("%3.0f %6.1f\n", f, c);
		f = f+step;
	}

	// printf("%d\n", 5/9); // 0 
}