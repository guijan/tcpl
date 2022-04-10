#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static int m_getchar(unsigned char *);

/* K&R C 2nd edition exercise 1-17: Write a program to print all input lines
 * that are longer than 80 characters
 */
int
main(void)
{
	enum {MAXLINE = 80};
	int rval;
	size_t i;
	unsigned char c;
	unsigned char line[MAXLINE + 1];
	int ret;

	i = 0;
	while ((ret = m_getchar(&c)) == 0) {
		if (c == '\n') {
			i = 0;
			continue;
		}
		line[i] = c;
		i++;
		if (i > MAXLINE) {
			fwrite(line, 1, i, stdout);
			while (m_getchar(&c) == 0) {
				putchar(c);
				if (c == '\n')
					break;
			}
		}
	}
	if (ret == -1) {
		rval = 1;
		perror(NULL);
	} else {
		rval = 0;
	}

	return (rval);
}

/* m_getchar: getchar() with multiple return values
 *
 * The character read is returned in *c, it is undefined on error.
 * Returns 0 on success, 1 on EOF, -1 on error.
 */
static int
m_getchar(unsigned char *c)
{
	int tmp;
	tmp = getchar();
	if (tmp == EOF) {
		if (feof(stdin))
			return (1);
		else if (ferror(stdin))
			return (-1);
	}
	*c = tmp;
	return (0);
}
