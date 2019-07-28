#include <stdio.h>

// // "" 是 char*
// main()
// {
// 	int c;

// 	while ((c = getchar()) != EOF)
// 	{
// 		if (c == ' ')
// 		{
// 			putchar(c);
// 			while ((c = getchar()) == ' ')
// 				;
// 		}
// 		putchar(c);
// 	}
// }

// prev 记忆上一个字符
#define NOBLANK '_'

main()
{
	int c, prev;

	prev = NOBLANK;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ')
		{
			putchar(c);
		}
		if (c == ' ' && prev != ' ')
		{
			putchar(c);
		}
		prev = c;
	}
}