// 1. Generate a k unique numbers randomly in the range 1 - n
// 2. check whether a given number is a perfect power of 2 in O(1) time
// 3. given 1 2 3 4 5 6 7 8 9 10, generate  5 6 7 8 9 10 1 2 3 4
//		input seq : a[l] to a[r], and l <= k <= r
//      output seq : a[k + 1] .. a[r] a[l] .. a[k]
// 4. Generate prime numbers

// 2
#include <stdio.h>
int is_exact_power_of_2(int n)
{
#if 0
	int c = 0;
	while(n != 0)
	{
		if(n & 0x01 == 1)
		{
			++c;
		}
		n >>= 1;
	}
	return c == 1;
#endif
	return (n & (n - 1)) == 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("res : %d\n", is_exact_power_of_2(n));
}
