#include <stdio.h>

main() {
	int c, i, nwhite, others;
	int nums[10];

	nwhite = others = 0;
	for (i = 0; i<10; i++) {
		nums[i] = 0;
	}

	while((c = getchar()) != EOF) {
		// C 的 if 要带上括号括号括号....
		if (c >= '0' && c <= '9') {
			nums[c-'0']++;
		} else if (c == ' ' || c == '\t' || c == '\n') {
			nwhite++;
		} else {
			others++;
		}
	}

	printf("nums = ");
	for (i = 0; i<10; i++) {
		printf(" %d", nums[i]);
	}
	printf(", white: %d", nwhite);
	printf(", others: %d", others);
}