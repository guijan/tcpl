#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1024
#define COLUMNS 80


int getlin(char *const s, const int len);
int sgetw(char *const s);

int
main(void)
{
	char s[MAXLINE];
	int i;
	int ret;
	int column;

	while ((ret = getlin(s, MAXLINE))) {
		for (i = 0, column = COLUMNS; s[i]; i++, column--) {
			if (sgetw(&s[i]) >= column) {
				putchar('\n');
				column = COLUMNS;
			}
			putchar(s[i]);
		}
		if (ret == EOF)
			break;
	}
}


int
getlin(char *const s, const int len)
{
	int i;
	int c;

	for (i = 0; (c = getchar()) != EOF && c != '\n' && i < len; i++)
		s[i] = c;
	s[i] = '\0';

	return (c == EOF ? c : i);
}

int
sgetw(char *const s)
{
	int i;

	for (i = 0; s[i] && isalnum(s[i]); i++)
		;

	return i;
}
