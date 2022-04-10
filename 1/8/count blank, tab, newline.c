#include <stdio.h>

int
main()
{
	int blnk, tab, nl, c = 0;
	nl = blnk = tab = c = 0;


	while ((c = getchar()) != EOF) {
		if (c == '\n')
			nl++;
		if (c == ' ')
			blnk++;
		if (c == '\t')
			tab++;
	}


	printf("BLANKS\tTABS\tNEWLINES\n");
	printf("%d\t%d\t%d\n", blnk, tab, nl);
	return 0;
}
