#include <stdio.h>

#define IN  1 // 在单词内
#define OUT 0 // 在单词外

main() {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while((c = getchar()) != EOF) {
		nc++;

		if (c == '\n') {
			nl++;
		} 
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT; // 单词结束
		} else if (state == OUT) { // 单词开始
			nw++;
			state = IN;
		}
	}

	printf("line:%d, word:%d, char:%d\n", nl, nw, nc);
}