#include <stdio.h>

main()
{
	float f, c;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	f = lower;
	printf("%s %s\n", "fhar", "celsius");
	while (f <= upper)
	{
		c = (f - 32.0) * 5.0 / 9.0;
		printf("%4.0f %6.1f\n", f, c);
		f = f + step;
	}
}