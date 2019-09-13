#include <stdio.h>

void strcpyn(char *src, char *dst, int n);

main() {
	char *s1 = "ABC";
	char *s2 = "abcdefg";
	strcpyn(s1, s2, 2);
	printf("%s\n", s1);
	printf("%s\n", s2);
}

// 实现带 n 参数的 strncpy
void strcpyn(char *s, char *t, int n) {
	do {
		if (n-- == 0)
			return;
	} while ((*s++ = *t++));

	while (n--) {
		*s++ = '\0';
	}
}