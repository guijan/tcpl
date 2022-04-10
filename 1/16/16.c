#include <stdio.h>
#define MAXLINE 256 /* maximum input line size */


int getlin(char *const line);

int
main(void)
{
	char line[MAXLINE] = { 0 };

	while (getlin(line) > 0) {

	}
}

/* getlin: Gets a line into the provided char array.
 *
 * Returns the line's length.
 * Returns EOF on EOF.
 * Returns 0 if line will not fit inside array
 */
int
getlin(char *const line)
{
	int c;
	int len = 0;
	int i;

	for (i = 0; (c = getchar()) != EOF; i++) {
		if (c == '\n') {
			line[i] = '\0';
			return len;
		} else if (i < MAXLINE) {}
			len++;
	}

	return EOF;
}
