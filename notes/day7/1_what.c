#include <stdio.h>

int add(int x, int y)
{
	return x + y;
}

int mul(int x, int y)
{
	return x * y;
}

int foo1(int a[], int n)
{
	int s = 0;
	for(int i = 0; i < n; ++i)
	{
		s += a[i];
	}
	return s;
}
int foo2(int a[], int n, int s)
{
	for(int i = 0; i < n; ++i)
	{
		s += a[i];
	}
	return s;
}
int max(int x, int y)
{
	return (x > y) ? x : y;
}
int foo3(int a[], int n, int s, int (*op)(int, int))
{
	for(int i = 0; i < n; ++i)
	{
		s = op(s, a[i]);
	}
	return s;
}
int main()
{
	int a[] = {11, 22, 33, 44, 55};
	printf("what : %d\n", foo1(a, 5));

	printf("what : %d\n", foo2(a, 5, 0));
	printf("what : %d\n", foo2(a, 5, 10000));

	printf("what : %d\n", foo3(a, 5, 0, add));
	printf("what : %d\n", foo3(a, 5, 1, mul));
	printf("what : %d\n", foo3(a + 1, 4, a[0], max));



}
