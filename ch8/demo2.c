#include <stdio.h>
#include <unistd.h>

// 将输入复制到输出
void redirect() {
	char buf[BUFSIZ];
	int n;
	while ((n = read(0, buf, BUFSIZ)) > 0)
		write(1, buf, n);
}

// 无缓冲单字符输入
int getchar1(void) {
	char c;
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

// 带简单缓冲的 getchar, 读取一组输入返回一个字符
int getchar2(void) {
	static char buf[BUFSIZ]; // static 静态变量会一直存活直到程序结束
	static char *bufp = buf;
	static int n = 0;

	// 缓冲区为空才读入
	if (n == 0) {
		n = read(STDIN_FILENO, buf, sizeof(buf));
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

// 8.2 低级IO: read/write
int main() {
	// redirect();
	// printf("%c\n", getchar1());
	printf("%c\n", getchar2());
	printf("%c\n", getchar2()); // 会保留输入的第二个字符
}

