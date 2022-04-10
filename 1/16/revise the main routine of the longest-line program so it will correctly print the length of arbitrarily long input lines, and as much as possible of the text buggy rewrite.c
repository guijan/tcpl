#include <stdio.h>

#define MAXLINE 80 /* maximum input line size */

void
copy(char from[],char to[])
{
	/* copy:
	 * copies from char array from[] to char array to[]
	 */

	int i;

	for (i = 0; from[i] != '\0'; ++i) {
		to[i] = from[i];
	}
}

int
getline_kr(char line[], int maxlen)
{
	/* getline_kr:
	 * kr stands for K&R, this was written for an exercise of the C book.
	 * Returns 0 if no line, the number of characters in the line if not
	 * over maxlen, and the number of characters in the line but negative
	 * if over maxlen.
	 */
	int i, c;

	for (i = 0; i < (maxlen - 1) && c != '\n' && (c = getchar()) != EOF; ++i) {
		line[i] = c;
	}

	if (c == '\n' && i < maxlen) {
		line[i] = '\n';
		++i;
	}

	line[i] = '\0';

	if (i == maxlen && getchar() != EOF) {
		return -i;
	} else {
		return i;
	}
}

int
main()
{
	/* These variables will be initialized upon usage. */
	int len;		/* line length */
	char line[MAXLINE];	/* the current line being worked on */
	char bigline[MAXLINE];	/* the biggest line we've found */
	/* These will not */
	int maxsz = 0;


	while ((len = getline_kr(line, MAXLINE)) != 0) {
		if (len > maxsz || -len > maxsz ) {
			copy(line, bigline);
		}
	}


	if (maxsz > MAXLINE) {
		printf("%s %d\n", "A line was over the maximum size of", MAXLINE);
	}
		printf("%s", bigline);
		return 0;
}
