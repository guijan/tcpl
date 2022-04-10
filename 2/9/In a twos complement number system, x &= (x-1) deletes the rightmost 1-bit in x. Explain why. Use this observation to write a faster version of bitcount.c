int
main(void)
{

}

int
bitcount(unsigned x)
{
	int b;
	/* Subtracting one from a number in an one's complement or two's
	 * complement system flips the LSB. When a variable is operated by & on
	 * itself subtracted by 1, the LSB bits always differ, and are always
	 * unset.
	 */
	for (b = 0; x &= (x -1); b++)
		x >>= 1;
	return b;
}

int krbitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
