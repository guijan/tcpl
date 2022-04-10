int
main(void)
{
	int i = 0;
	while (i+++) {
		if (!(i<lim-1))
			break;
		if (!((c = getchar()) != '\n'))
			break;
		if (!(c != EOF))
			break;
		s[i] = c;
	}
}
