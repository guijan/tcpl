#include <stdio.h>
#define MAX 1024

void newsqueeze(char *const, char *const);

int
main(void)
{
	char line[] = "where have all the good men gone and where are all the";
	char exclude[] = "ae";

	newsqueeze(line, exclude);

	printf("%s\n", line);
}

void newsqueeze(char *const s1, char *const s2)
{
	int i, j, k;

	for (i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; s1[i] != s2[k]; k++) {
			if (s2[k] == '\0') {
				s1[j++] = s1[i];
				break;
			}
		}
	}

	s1[j] = '\0';

}

/* squeeze: delete all c from s */
void squeeze(char *const s, const int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

