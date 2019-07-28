#include <stdio.h>

main()
{
	float f, c;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	c = lower;
	printf("%s\t%6s\n", "celsius", "fhar"); // %Ns valid too
	while (c <= upper)
	{
		f = c * 9.0 / 5.0 + 32.0;
		printf("%4.0f\t%6.1f\n", c, f);
		c = c + step;
	}
}