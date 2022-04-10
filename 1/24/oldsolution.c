#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1024
#define ACNT(n) (sizeof(n) / sizeof(*n))

int getlin(char *const, const int);

typedef struct
{
	const char pairs[3][2];
} MATCHES;


int
main(void)
{
	int c;
	int plvl = 0;
	int braklvl = 0;
	int braclvl = 0;
	char s[MAXLINE];

	while (getlin(s, ACNT(s)) > 0) {

	}
}

int getlin(char *const s, const int lim)
{
	int i;
	int c;

	for (i = 0; (c = getchar()) != EOF && c != '\n' && c < lim; i++)
		s[i] = c;
	s[i] = '\0';

	if (c == EOF && c == lim)
		return i;
	else
		return (c == EOF ? EOF : i);
}

MATCHES *
init_matches()
{
	MATCHES *ret = malloc(sizeof(MATCHES));

	if (ret == NULL)
		return ret;

	ret->pairs = {
		{'(', ')'},
		{'[', ']'},
		{'{', '}'}
	};

}
