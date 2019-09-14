#include <stdio.h>
#include <stdarg.h>

void miniPrintf(char *fmt, ...);

// 7.3 变长参数列表
int main() {
	miniPrintf("%d %s %f", 1, "demo", 1.1);
}


void miniPrintf(char *fmt, ...) {
	va_list ap; // 声明参数指针，依次指向函数的参数列表
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); // 从最后一个有名参数开始
	for (p = fmt; *p; p++) {
		if (*p != '%') { // 非修饰符直接输出
			putchar(*p);
			continue;
		}

		switch (*++p) { // 跳过修饰符
			case 'd':
				ival = va_arg(ap, int); // 给定类型名，来决定返回的对象类型，向后移动的步长
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char*); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
		}
	}

	va_end(ap);
}