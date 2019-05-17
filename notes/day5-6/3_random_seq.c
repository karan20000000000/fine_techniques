#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int a[], int n)
{
	for(int i = 1; i <= n; ++i)
	{
		a[i] = i;
	}

}
void myswap(int *x, int *y)
{
	int temp = *x; *x = *y; *y = temp;
}
void randomize(int a[], int n)
{
	srand(time(0));
	for(int i = 1; i < n / 2; ++i)
	{
		int j = rand() % n + 1;
		myswap(&a[i], &a[j]);
	}
}
void disp(int a[], int n)
{
	for(int i = 1; i <= n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[1000001];
	int n;
	scanf("%d", &n);
	init(a, n);
	randomize(a, n);
	disp(a, n);
}
