#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>

#define PERMS 0666

// 自定义错误格式化处理函数
void error(char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

// 8.3 open, creat, close, unlink
// 实现文件拷贝 cp 函数
int main(int argc, char *argv[]) {
	if (argc != 3)
		error("usage: cp from to");

	int f1, f2, n;
	char buf[BUFSIZ];

	// 打开源文件
	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
		error("cp: can't open %s", argv[1]);
	// 创建新文件
	if ((f2 = creat(argv[2], PERMS)) == -1)
		error("cp: can't creat %s, mode %03o", argv[2], PERMS);

	// 开始复制
	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(f2, buf, n) != n)
			error("cp: write error on file %s", argv[2]);

	close(f1); // 释放文件描述符，但不像 fclose 会冲刷缓冲区
	close(f2);
	return 0;
}

