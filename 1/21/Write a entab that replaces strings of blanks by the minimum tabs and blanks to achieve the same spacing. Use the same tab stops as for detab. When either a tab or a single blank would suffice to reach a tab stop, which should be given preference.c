#include <stdio.h>
#define TABSTOP 8

int
main(void)
{
	int c;
	int spaces = 0;

	while ((c = getchar()) != EOF) {
		switch(c) {
		case ' ':
			spaces++;
			if (spaces == TABSTOP) {
				putchar('\t');
				spaces = 0;
			}
			break;
		default:
			if (spaces) {
				do {
					putchar(' ');
				} while (--spaces);
			}
			putchar(c);
			break;
		}
	}
	if (spaces) {
		do {
			putchar(' ');
		} while (--spaces);
	}
}
