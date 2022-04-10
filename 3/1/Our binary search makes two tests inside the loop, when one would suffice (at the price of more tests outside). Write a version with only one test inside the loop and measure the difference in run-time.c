

int
main(void)
{

}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n -1] */
int
binsearch(int x, int *v, int n)
{
	int left, middle, right;

	left = 0;
	right = n - 1;

	while (left != right) {
		middle = (left+right) / 2;
		if (v[middle] > x)
			right = middle - 1;
		else
			left = middle;
	}

	return (v[left] == x ? left : -1);
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n -1] */
int
krbinsearch(int x, int *v, int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /*found match */
			return mid;
	}
	return -1;
}
