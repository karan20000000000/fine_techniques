#include <stdio.h>
const size_t SIZE=sizeof(int);
#define MAX 1000
// closed : 0
// open : 1
void disp_open(unsigned int cell[], int n)
{	
	int base;
	int offset;
	for(int i = 1; i <= n; ++i)
	{
		base = i / SIZE;
		offset = i % SIZE; 
		if(cell[base] & (0x01 << offset) )
		{
			printf("%d ", i);
		}
	}
}
void close_all(unsigned int cell[], int n)
{
	for(int i = 1; i <= n / SIZE + 1; ++i)
	{
		cell[i] = 0;
	}
}

void open_and_close(unsigned int cell[], int n) 
{
	int base;
	int offset;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; j += i)
		{
			base = j / SIZE;
			offset = j % SIZE; 
			if(cell[base] & (0x01 << offset))
			{
				cell[base] &= ~(0x01 << offset);
			}
			else
			{
				cell[base] |= 0x01 << offset;
			}
		}
	}
}
int main()
{
	unsigned int cell[MAX];
	int n;
	scanf("%d", &n);
	close_all(cell, n);
	open_and_close(cell, n);	
	disp_open(cell, n);
}
