#include <stdio.h>

int
main()
{
	int c;


	while ((c = getchar()) != EOF) {
		switch (c) {
		case '\t':
				printf("%s", "\\t");
				break;
		case '\b':
				printf("%s", "\\t");
				break;
		case '\\':
				printf("%s", "\\\\");
				break;
		default:
				putchar(c);
				break;
		}
	}


	return 0;
}
