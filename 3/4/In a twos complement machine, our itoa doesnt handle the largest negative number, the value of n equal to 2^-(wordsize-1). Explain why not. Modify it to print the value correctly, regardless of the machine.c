#include <string.h>
#include <limits.h>


static void reverse(char *s);

int
main(void)
{

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

/* Does not work every time on two's complement machines because the minimum
 * value of a signed data type in two's complement is one less than the
 * maximum inverted. For instance, the minimum value of an 8-bit signed value
 * in two's complement is -128, while the maximum is 127.
 */
int
kritoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0) /* record sign */
		n = -n;
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

	return 0;
}

static void
reverse(char *s)
{
	/* Arrays start at 0, but the strlen value starts at 1. Subtract 1. */
	int top = strlen(s) - 1;
	int bot;
	char c;

	for (bot = 0; top > bot; top--, bot++) {
		c = s[bot];
		s[bot] = s[top];
		s[top] = c;
	}
}
