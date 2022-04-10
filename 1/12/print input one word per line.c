#include <stdio.h>
#include <ctype.h>

int
main()
{
	int c = -1; /* character */
	int bt = -1; /* blank transition. 1 if the last character was a blank */

	while ((c = getchar()) != EOF) {
		if (isspace(c)) {
			if (bt) {
				continue;
			} else {
				bt = 1;
				putchar('\n');
			}
		}
		if (isgraph(c)) {
			bt = 0;
			putchar(c);
		}
	}
	return 0;
}
