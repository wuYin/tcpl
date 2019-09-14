#include <stdio.h>

// 7.5 文件访问
int main(int argc, char *argv[]) {
	// cat v1: 连接多个文件
	FILE *fp;
	void fileCopy(FILE *, FILE *);
	if (argc == 1) {
		fileCopy(stdin, stdout); // 只有一个参数则复制标准输入到标准输出
		return 0;
	}

	while (--argc > 0)
		if ((fp = fopen(*++argv, "r")) == NULL) {
			printf("cat can't open file: %s\n", *argv);
			return 1;
		} else {
			fileCopy(fp, stdout);
			fclose(fp); // 关闭打开的文件指针，释放文件资源，flush 写缓存
		}
}

void fileCopy(FILE *ifp, FILE *ofp) {
	int c;
	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}