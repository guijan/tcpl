#include <stdio.h>
#define MAXLINE 1024


int getlin(char *const s, const int lim);

int
main(void)
{
	char s[MAXLINE];
	int ret;
	int unq = 1; /* unquoted */
	int i;
	int esc = 0;

	while (1) {
		ret = getlin(s, MAXLINE);
		for (i = 0; s[i]; i++) {
			if (s[i] == '/' && s[i+1] == '*' && !esc) {
				unq = 0;
				i++;
				continue;
			} else if (s[i] == '*' && s[i+1] == '/' && !unq && !esc) {
				i++;
				unq = 1;
				continue;
			} if (s[i] == '\\')
				esc = 1;
			else
				esc = 0;
			if (unq)
				putchar(s[i]);
		}
		putchar('\n');
		if (ret == EOF)
			break;
	}
}

int
getlin(char *const s, const int lim)
{
	int c;
	int i;

	for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim; i++)
		s[i] = c;
	s[i] = '\0';

	if (c == EOF && i == lim)
		return i;
	return (c == EOF ? c : i);
}
