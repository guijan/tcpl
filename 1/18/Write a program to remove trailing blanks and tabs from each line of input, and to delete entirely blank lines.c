#include <stdio.h>
#define MAXLINE 1024

int getnobl(char *const, const int);

int
main(void)
{
	char line[MAXLINE];
	int len;

	while ((len = getnobl(line, MAXLINE)) != EOF) {
		if (len) {
			printf("%s\n", line);
		}
	}
	if (line[0]) {
		printf("%s\n", line);
	}

}

int
getnobl(char *const line, const int length)
{
	int i, c;
	int j = 0;

	for (i = 0; (c = getchar()) != EOF && c != '\n' && i < length; i++) {
		switch (c) {
		default:
			j = i;
			/* Move j 1 character past the last non-blank. That
			 * means it's set to the first blank of a sequence
			 * of blanks
			 */
			j++;
			/* FALLTHROUGH */
		case  ' ':
		case '\t':
			line[i] = c;
			break;
		}
	}
	line[j < i ? j : i] = '\0';

	return (c == EOF ? c : i);
}
