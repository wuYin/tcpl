#include <stdio.h>

#define MAX_LINE 1000

// 不使用 && 和 || 写出以下逻辑的等价语句
// for(i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; i++)

int getOneLine(char s[], int lim);

main() {
	char line[MAX_LINE];
	int n;
	if (getOneLine(line, MAX_LINE) > 0)
		printf("%s", line);
}

enum loop {
	NO, // 0
	YES // 1
};

enum loop ok = YES; // 枚举变量前缀也需 enum 修饰符，和 struct 一致

int getOneLine(char s[], int lim) {
	int i = 0;
	int c;
	while (ok)
		if (i >= lim - 1)
			ok = NO;
		else if ((c = getchar()) == EOF)
			ok = NO;
		else if (c == '\n')
			ok = NO;
		else
			s[i++] = c;

	return i;
}