#include <stdio.h>
#define LINELEN BUFSIZ * 4

size_t escp(const char *s, char *t, size_t tlen);
size_t unescp(const char *s, char *t, size_t tlen);

int
main(void)
{

}

size_t
escp(const char *s, char *t, size_t tlen)
{
	for (; *s != '\0' && tlen > 0; s++, t++, tlen--) {
		switch (*s) {
		case '\t':
			if (--tlen > 0) {
				*t = '\\';
				*++t = 't';
			} else
				goto end;
			break;
		case '\n':
			if (--tlen > 0) {
				*t = '\\';
				*++t = 'n';
			} else
				goto end;
			break;
		case '\b':
			if (--tlen > 0) {
				*t = '\\';
				*++t = 'b';
			} else
				goto end;
			break;
		default:
			*t = *s;
			break;
		}

	}

	*t = '\0';
end:
	return (tlen);
}

size_t
unescp(const char *s, char *t, size_t tlen)
{
	for (; *s != '\0' && tlen > 0; s++, t++, tlen--) {
		if (*s == '\\' && s[1] != '\0') {
			switch (s[1]) {
			case 't':
				*t = '\t';
				s++;
				break;
			case 'n':
				*t = '\n';
				s++;
				break;
			case 'b':
				*t = '\b';
				s++;
				break;
			default:
				*t = *s;
				break;
			}
		} else
			*t = *s;
	}

	return (tlen);
}
