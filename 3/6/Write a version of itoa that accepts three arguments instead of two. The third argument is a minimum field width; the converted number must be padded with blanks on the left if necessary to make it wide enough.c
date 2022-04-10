#include <string.h>
#include <limits.h>


static void reverse(char *s);

int
main(void)
{

}

int
itoa3arg(int n, char s[], unsigned int pad)
{
	unsigned int i;
	int sign = 0;
	const int signmask = ~0U >> 1;

	if (n < 0)
		sign = n;


	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = ((n % 10) & signmask) + '0';	/* get next digit */
	} while ((n /= 10) != 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';

	/* Pad with zeroes */
	while (i < pad && s[i != '\0'])
		s[i++] = '0';
	s[i] = '\0';
	reverse(s);

	return 0;
}

int
itoa(int n, char s[])
{
	int i;
	int sign = 0;
	const int signmask = ~0U >> 1;

	if (n < 0)
		sign = n;

	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = ((n % 10) & signmask) + '0';	/* get next digit */
	} while ((n /= 10) != 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

	return 0;
}
