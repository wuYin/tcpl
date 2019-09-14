#include <stdio.h>
#include <string.h>

// 7.7 行输出与行输出
// 从 in 文件中读取最多 n-1 个字符，最后以空字符结尾
char *fgetstr(char *s, int n, FILE *infp) {
	int c;
	char *cs;
	cs = s;
	while (--n > 0 && (c = getc(infp)) != EOF) {
		if ((*cs++ = c) == '\n') {
			break;
		}
	}
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s; // 若未读取到数据则返回 NULL
}

int fputstr(char *s, FILE *outfp) {
	int c;
	while (c = *s++) {
		putc(c, outfp);
	}
	return ferror(outfp) ? EOF : -1;
}

int getlines(char *line, int max) {
	if (fgetstr(line, max, stdin) == NULL) {
		return 0;
	}
	return strlen(line);
}

int main() {
	char *line = (char *) malloc(100); // 必须先分配内存
	printf("%d\n", getlines(line, 100));
	printf("%s\n", line);
}

