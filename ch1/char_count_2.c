#include <stdio.h>

main() {
	double nc;

	for (nc = 0; getchar() != EOF; ++nc) // 空语句换行可读性更好
		; 
	printf("%.0f\n", nc);
}