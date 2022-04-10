#include <stdio.h>


int
main()
{
	int c = 0;
	/* b == blank.
	 * 1 == The last character was a blank.
	 * 0 == The last character was not a blank.
	 */
	int b = 0;





	while ((c = getchar()) != EOF) {
		if (b == 1 && c != ' ') {
			putchar(' ');
			putchar(c);
			b = 0;
		} else if (c == ' ') {
			b = 1;
		} else {
			putchar(c);
		}
	}

	return 0;
}
