#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINE 1024
#define ACNT(n) (sizeof(n) / sizeof(*n))

int getlin(char *const, const int);

int
main(const int argc, const char *const *const argv)
{
	char s[MAXLINE];
	int linelen;
	int i;
	int ret = 1;

	int plvl = 0;		/* parentheses	 */
	int braklvl = 0;	/* brackets	 */
	int braclvl = 0;	/* braces	 */

	int cconstant = 0;
	int commented = 0;
	int escaped = 0;
	int literal = 0;

	while ((linelen = getlin(s, ACNT(s)))) {
		for (i = 0; isblank(s[i]); i++)
			;
		if (s[i] == '#')
			continue;

		for (; s[i]; i++) {
			if (s[i] == '\\' && !escaped)
				escaped = 2;
			else if (escaped)
				escaped--;

			if (!escaped) {
				if (!cconstant && !literal) {
					if (s[i] == '/' && s[i+1] == '*' )
						commented = 1;
					else if (s[i] == '*' && s[i+1] == '/')
						commented = 0;
				}
				if (!commented) {
					if (!literal && s[i] == '\'')
						cconstant = !cconstant;
					else if (!cconstant && s[i] == '"')
						literal = !literal;
				}
			}


			if (!cconstant && !commented && !escaped && !literal) {
				switch(s[i]) {
				case '(':
					plvl++;
					break;
				case ')':
					plvl--;
					break;
				case '[':
					braklvl++;
					break;
				case ']':
					braklvl--;
					break;
				case '{':
					braclvl++;
					break;
				case '}':
					braclvl--;
					break;
				case '\n':
					if (
					    literal || commented ||
					    braclvl || braklvl || plvl
					) goto end;
					break;
				}
			}
		}
		if (linelen <= 0)
			break;
	}

	ret = 0;
end:
	if (literal || commented || braclvl || braklvl || plvl) {
		printf("%s: %s\n", argv[0], "errors found.");
		ret = 1;
	}
	return ret;
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
		return (c == EOF ? c : i);
}
