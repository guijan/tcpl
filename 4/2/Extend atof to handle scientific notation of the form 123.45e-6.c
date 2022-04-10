#include <ctype.h>



/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign, xp;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	if (isdigit(s[i]) || s[i] == '+')
		for (xp = atof(&s[i]); xp > 0; xp--)
			power /= 10.0;
	else if (s[i++] == '-')
		for (xp = atof(&s[i]); xp > 0; xp--)
			power *= 10.0;

	return sign * val / power;
}
