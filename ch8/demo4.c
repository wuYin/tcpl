#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// 在文件中从任意位置读取任意长度
int get(int fd, long pos, char *buf, int n) {
	if (lseek(fd, pos, 0) >= 0) // 发生错误返回 -1
		return read(fd, buf, n);
	else
		return -1;
}

// 8.4 随机访问 lseek
int main() {
	int fd;
	char buf[BUFSIZ];

	if ((fd = creat("demo.txt", 0666)) == -1)
		return -1;

	if (write(fd, "123456789", 9) == -1)
		return -2;

	if (get(fd, 2, buf, 2) > 0)
		printf("%s\n", buf);

	close(fd);
	unlink("demo.txt");
}