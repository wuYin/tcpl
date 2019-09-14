#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))


// 7.8 其他函数
int main() {
	// 字符串操作函数
	char s1[10] = "abc";
	char *s2 = "def";
	strcat(s1, s2);
	printf("%s\n", s1);
	printf("%s\n", strchr("abcbcdef", 'b'));
	printf("%s\n", strrchr("abcbcdef", 'b'));

	// 字符类别测试与转换
	printf("%d %d\n", isalpha('a'), isalpha('1'));
	printf("%d %d\n", isupper('A'), isupper('a'));
	printf("%d %d\n", islower('a'), islower('A'));
	printf("%d %d\n", isdigit('1'), isdigit('A'));
	printf("%d %d %d\n", isalnum('a'), isalnum('1'), isalnum('$'));
	printf("%d %d\n", isspace(' '), isspace('/'));
	printf("%c %c\n", toupper('c'), tolower('C'));

	// 命令执行函数
	system("date");
	system("ls -lha | head -n 2");

	// 内存分配函数
	int *p1 = (int *) malloc(sizeof(int));
	int *p2 = (int *) calloc(2, sizeof(int));
	printf("%d\n", *p1);
	printf("%d\n", *p2);
	free(p2);
	free(p1);

	// 数学函数
	printf("%f\n", pow(2, 4));
	printf("%f\n", sqrt(4));
	printf("%f\n", fabs(-4));

	// 随机数发生器
	srand((unsigned int)time(NULL));
	printf("%d\n", frand());
}

