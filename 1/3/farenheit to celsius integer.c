#include <stdio.h>

int main()
{
	/*  C = (5/9(F-32) */
	int celsius, fahr;
	int lower, step, upper;

	lower	= 0;
	step	= 20;
	upper	= 300;

	fahr	= lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;


		printf("%d\t%d\n", celsius, fahr);


		fahr = fahr + step;
	}


}
