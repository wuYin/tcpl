#include <stdio.h>

main()
{
	int c;
	int space, tab, line;
	space = 0;
	tab = 0;
	line = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			space++;
		}
		else if (c == '\t')
		{
			tab++;
		}
		else if (c == '\n')
		{
			line++;
		}
	}

	printf("space:%d, tab:%d, line:%d\n", space, tab, line);
}