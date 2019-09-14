#include <stdio.h>

// 7.6 错误处理 stderr 和 exit
int main(int argc, char *argv[]) {
	// cat v2: 连接多个文件
	FILE *fp;
	void fileCopy(FILE *, FILE *);
	char *execName = argv[0]; // argv[0] 暂存执行程序名称，之后 argv 指针会后移
	if (argc == 1) {
		fileCopy(stdin, stdout);
		return 0;
	}

	printf("%s\n", "------");

	while (--argc > 0) {
		if ((fp = fopen(*++argv, "r")) == NULL) {
			fprintf(stderr, "%s: can't open %s\n", execName, *argv);
			exit(1); // 终止程序执行，调用方可通过 $? 获取退出状态
		} else {
			fileCopy(fp, stdout);
			fclose(fp);
		}
	}

	if (ferror(stdout)) {
		fprintf(stderr, "%s: error occurred when writing stdout\n", execName);
		exit(2);
	}
	exit(0);
}

void fileCopy(FILE *infp, FILE *outfp) {
	int c;
	while ((c = getc(infp)) != EOF)
		putc(c, outfp);
}