#include <stdio.h>

#define MAXLEN 99 /* Maximum word length */


int
main()
{
	/* Prints a text-based histogram of word lengths. */


	/* These are initialized upon usage. */
	int c, i, i2; /* Character, iteration, iteration2. */

	/* These are not. */
	int count; /* How many characters were counted so far. */

	/* The subscript's number is the word's size, and its value is how
	 * many words had that word size.
	 * subscript 0 is the biggest word in the array's size.
	 */
	int len[MAXLEN];

	for (i = 0; i <= MAXLEN; i++) {
		len[i] = 0;
	}
	count = 0;


	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ') {
			if (count > 0) {
				len[count]++;
			}
			if (count > len[0]) {
				len[0] = count;
			}
			count = 0;
		} else {
			if (count == MAXLEN) {
				printf("%s %d.\n", "ERROR: Word length above maximum of", MAXLEN);
				return 1;
			}
			count++;
		}
	}

	putchar('\n');
	for (i = 1; i <= len[0]; i++) {
		if (len[i] > 0)
			printf("%d", i);
	}
	putchar('\n');

	for (i = 1; i <= len[0]; i++) {
		if (len[i] < 10)
			putchar('-');
		if (len[i] > 10)
			printf("%s", "--");
	}
	putchar('\n');


	for (i = 1; i <= len[0]; i++) {
		for (i2 = 1; i2 <= len[0]; i2++) {
			if (len[i2] > 0) {
				putchar('#');
				--len[i2];
			} else {
				putchar(' ');
			}
		}
		putchar('\n');
	}

	return 0;
}
