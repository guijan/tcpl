#include <stdio.h>

int main()
{
	/*  C = (5/9(F-32) */
	int celsius;
	float fahr;
	int lower, step, upper;

	lower	= 0;
	step	= 20;
	upper	= 300;

	celsius = lower;
	while (celsius <= upper) {
		fahr = celsius * (9.0 / 5.0) + 32.0;


		printf("%d\t%6.2f\n", celsius, fahr);


		celsius = celsius + step;
	}


}
