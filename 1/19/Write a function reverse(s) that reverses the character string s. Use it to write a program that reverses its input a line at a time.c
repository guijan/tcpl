#include <stdio.h>
#include <string.h>
#define MAXLINE 1024
#define ACNT(n) ((sizeof(n)) / (sizeof(*n)))

void reverse(char *);
int getlin(char *const, const int);

int
main(void)
{
	char line[MAXLINE];

	while (getlin(line, ACNT(line)) != EOF) {
		reverse(line);
		printf("%s\n", line);
	}
}

int
getlin(char *const s, const int lim)
{
	int i, c;

	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < lim; i++)
		s[i] = c;

	s[i] = '\0';
	return (c == EOF ? c : i == lim);
}

void
reverse(char *s)
{
	/* Arrays start at 0, but the strlen value starts at 1. Subtract 1. */
	int top = strlen(s) - 1;
	int bot;
	char c;

	for (bot = 0; top > bot; top--, bot++) {
		c = s[bot];
		s[bot] = s[top];
		s[top] = c;
	}
}
