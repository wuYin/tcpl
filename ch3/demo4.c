#include <stdio.h>

// 3.4 switch 语句
// C 的 switch 默认是 fallthrough
// 统计输入的数字、空白符和其他符号
main() {
	int c, i;
	int nSpace, nOther, nDigits[10];
	nSpace = nOther = 0;
	for (i = 0; i < 10; i++) // 显式初始化
		nDigits[i] = 0;

	while ((c = getchar()) != EOF) {
		switch (c) {
			case '0': // C 中默认未手动 break 则 fallthrough
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				nDigits[c - '0']++;
				break;

			case ' ':
			case '\t':
			case '\n':
				nSpace++;
				break;
			default:
				nOther++;
				break;
		}
	}

	printf("digits: ");
	for (i = 0; i < 10; i++)
		printf(" %d", nDigits[i]);
	printf(", white: %d, other:%d\n", nSpace, nOther);
}