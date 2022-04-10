#include <stdio.h>

int main()
{
	/*  C = (5/9(F-32) */
	float celsius;


	for (celsius = 300.0; celsius >= 0.0; celsius = celsius - 20.0)
		printf("%3.0f\t%3.0f\n", celsius, celsius * (9.0 / 5.0) + 32.0);


}
