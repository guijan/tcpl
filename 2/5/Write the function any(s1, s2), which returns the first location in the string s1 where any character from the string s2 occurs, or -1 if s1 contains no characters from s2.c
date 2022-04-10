#include <stdio.h>

int any(const char *const s1, const char *const s2);

int
main(void)
{
	char line[] = "fuck shit A";
	char test[] = "A";

	return any(line, test);
}

int
any(const char *const s1, const char *const s2)
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
	return -1;
}
