#include <stdio.h>
#define TABSTOP 8

int
main(void)
{
	int c;
	int totab = TABSTOP;

	while ((c = getchar()) != EOF) {
		switch(c) {
		case '\t':
			while (totab--) {
				putchar(' ');
			}
			break;
		default:
			totab == 0 ? totab = TABSTOP : totab--;
			putchar(c);
			break;
		}
	}
}
