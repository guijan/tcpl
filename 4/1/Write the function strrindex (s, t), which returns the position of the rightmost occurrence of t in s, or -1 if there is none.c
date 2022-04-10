

int
main(void)
{

}

int
strrindex(char *s, char *t)
{
	int i = 0;
	int ret = -1;

	for (i = 0; *s != '\0'; s++, i++)
		while(*s == *t++)
			if (*t == '\0')
				ret = i;
	return ret;
}
