int
main(void)
{
}

int
lower(int c)
{
	return (c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c);
}

int
krlower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
