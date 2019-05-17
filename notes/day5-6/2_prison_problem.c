#include <stdio.h>
#define MAX 1001
// closed : 0
// open : 1
void disp_open(int cell[], int n)
{
	for(int i = 1; i <= n; ++i)
	{
		if(cell[i])
		{
			printf("%d ", i);
		}
	}
}
void close_all(int cell[], int n)
{
	for(int i = 1; i <= n; ++i)
	{
		cell[i] = 0;
	}
}

void open_and_close(int cell[], int n) 
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; j += i)
		{
			cell[j] = ! cell[j];
		}
	}
}
int main()
{
	int cell[MAX];
	int n;
	scanf("%d", &n);
	close_all(cell, n);
	open_and_close(cell, n);	
	disp_open(cell, n);
}
