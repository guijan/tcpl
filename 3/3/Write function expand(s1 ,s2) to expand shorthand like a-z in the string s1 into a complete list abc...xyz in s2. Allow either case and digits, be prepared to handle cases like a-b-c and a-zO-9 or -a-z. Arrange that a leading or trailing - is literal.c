#include <stdio.h>
#include <limits.h>
#include <assert.h>

ssize_t nexpand(const char *s, char *t, ssize_t tlen);
ssize_t expand(const char *s, char *t, ssize_t tlen);
static ssize_t scat(
		char,
		char const,
		char *,
		ssize_t
);

int
main(void)
{
	char buf[BUFSIZ];

	printf("%lu\n", expand("-a-f-za-z-", buf, sizeof(buf)));
	printf("%s\n", buf);
}

/* expand: expand lexicographical range of characters into array of char.
 *
 * *s is the source array.
 * *t is the target array.
 * tlen is the maximum number of bytes to write into the array.
 *
 * Returns 0 or the number of bytes left on success.
 * Returns the number of bytes left inverted on error.
 */
ssize_t
expand(const char *s, char *t, ssize_t tlen)
{
	char min = 0;
	char max = 0;
	ssize_t ret = 0;
	/* 0 for start of range. 1 for '-' stage. */
	int status = 0;

	for (; *s != '\0' && tlen > 0; s++) {
		if (*s == '-') {
			if ((!min && !max) || s[1] == '\0') {
				printf("%s\n", "prepend");
				*t++ = '-';
				tlen--;
			} else {
				printf("%s\n", "status");
				status = 1;
			}
		} else {
			if (status) {
				max = *s;
				if ((ret = scat(min, max, t, tlen)) < 0) {
					printf("%s\n", "fail");
					goto end;
				} else {
					printf("%s %ld\n", "success", ret);
					tlen -= ret;
					t += ret;
					min = *s;
					status = 0;
					if (s[1] == '-' && s[2] != '\0')
						t--, tlen++;
				}
			} else
				min = *s, printf("%s\n", "lewd");
		}
	}

end:
	*t = '\0';
	return (*s == '\0' ? tlen : -tlen);
}

/* scat: Print lexicographical range of characters into string.
 *
 * start is the start of the range.
 * end is the end of the range.
 * *t is the target array of char.
 * tlen is the maximum bytes to write to the array of char t.
 *
 * Returns 0 or the amount of bytes left on success.
 * Returns the amount of bytes left inverted (<0) on error.
 */
static ssize_t
scat(char start, char const end, char *t, ssize_t tlen)
{
	int i;
	assert(start <= end);
	for (i = 0; tlen > 0 && start <= end; tlen--, start++, t++, i++)
		*t = start;

	return (start == end + 1 ? i : -tlen);
}
