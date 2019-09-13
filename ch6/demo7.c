#include <stdio.h>

// 6.7 类型定义
int main() {
	typedef char *String;
	String p = (String) malloc(100);
}