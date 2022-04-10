#include <limits.h>

int
main(void)
{

}

int
rightrot(int x, const int n)
{
	/* Hold with the bits that will fall off the right */
	int hold = ~(~0 << n) & x;
	hold <<= (sizeof(int) * CHAR_BIT - n);

	x = *(unsigned int *)&x >> n;
	x |= hold;

	return x;
}
