#include <stdio.h>


int htoi(const char *const s);


int
main(void)
{
	printf("%d\n", htoi("0xFF"));
}

int
htoi(const char *const s)
{
	int i = 0;
	int n = 0;

	if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
		i += 2;

	for (; s[i] != '\0'; i++) {
		if (s[i] >= '0' && s[i] <= '9' )
			n = 16 * n + (s[i] - '0');
		else if (s[i] >= 'a' && s[i] <= 'f' )
			n = 16 * n + (s[i] - 'a' + 10);
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - 'A' + 10);
		else {
			n = -1;
			break;
		}
	}

	return n;
}

int
atoi(const char *const s)
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}


