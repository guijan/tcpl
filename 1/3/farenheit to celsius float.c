#include <stdio.h>

int main()
{
	/*  C = (5/9(F-32) */
	float celsius;
	int fahr;
	int lower, step, upper;

	lower	= 0;
	step	= 20;
	upper	= 300;

	fahr	= lower;
	while (fahr <= upper) {
		celsius = 5.0/9.0 * (fahr - 32);


		printf("%6.2f\t%d\n", celsius, fahr);


		fahr = fahr + step;
	}


}
