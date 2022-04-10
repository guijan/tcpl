#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20



float
cel_to_fahr(int celsius)
{
	/* Converts Celsius to Fahrenheit */
	/* Formula: Celsius = 5 * (F-32) / 9 */

	return celsius * 1.8 + 32.0;
}


int
main()
{
	int i;

	printf("%s\t%s\n", "CELSIUS", "FARENHEIT");
	for (i = LOWER; i <= UPPER; i = i + STEP) {
		printf("%6d\t%6.1f\n", i, cel_to_fahr(i));
	}

	return 0;
}
