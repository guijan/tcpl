#include <stdio.h>
#define MAX_CHAR 65536 /* biggest numeric value a character may produce */

int
main()
{
	/* These variables are set up as they are used */
	int i, c;

	/* These variables are not set up as they are used */
	/* chars[] stores the frequency of ASCII characters.
	 * chars[0] is the character with the biggest decimal representation.
	 * chars[1] to chars[MAX_CHAR] are the text character with that
	 * decimal representation
	 */
	int chars[MAX_CHAR];

	for (i = 0; i <= MAX_CHAR; i++) {
		chars[i] = 0;
	}


	while ((c = getchar()) != EOF ) {
		if (c > MAX_CHAR) {
			printf("%s %d %s %d\n", "ERROR: Character with value", c, "is over maximum character size", MAX_CHAR);
		}
		++chars[c];
		if (c > chars[0]) {
			chars[0] = c;
		}
	}

	for (i = 33; i <= chars[0]; ++i) { /* characters up to 32 are control characters */
		if (chars[i] > 0) {
			putchar(i);
			putchar('|');
			for (; chars[i] > 0; --chars[i]) {
				putchar('=');
			}
			putchar('\n');
		}
	}

	return 0;
}
