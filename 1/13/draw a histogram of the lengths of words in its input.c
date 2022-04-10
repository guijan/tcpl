#include <stdio.h>

#define MAXLEN 32 /* Maximum word length */

int
main()
{
	/* Prints a text-based histogram of word lengths. */

	int c, i, i2, count;
	int len[MAXLEN];
	c = i = i2 = count = 0;
	for (i=0; i <= MAXLEN; i++) {
		len[i] = 0;
	}


	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ') {
			len[count]++;
			count = 0;
		} else {
			if (count == MAXLEN) {
				printf("%s %d\n", "ERROR: Character count over maximum word length of", MAXLEN);
				return 1;
			}
			count++;
		}
	}

	printf("%s\n", "Horizontal bars = word count.");
	printf("%s\n", "Numbers = word length.");
	for (i = 1; i <= MAXLEN; i++) {
		if (len[i] > 0) {
			printf("%2d|", i);
			for (i2 = 1; i2 <= len[i]; i2++) {
				putchar('=');
			}
		putchar('\n');
		}

	}

	return 0;
}
