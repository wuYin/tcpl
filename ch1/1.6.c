#include <stdio.h>

main()
{
	int c;

	while (c = getchar() != EOF)
	{
		printf("%d\n", c); // C 中 0 false / 1 true
		putchar(c);
	}
	printf("%x\n", c); // 0D
}