#include <stdio.h>
#include <stdlib.h>
const size_t SIZE = sizeof(unsigned int);
void disp(unsigned int a[], int n)
{	
	int base;
	int offset;
	for(int i = 1; i <= n; ++i)
	{
		base = i / SIZE;
		offset = i % SIZE; 
		if(a[base] & (0x01 << offset) )
		{
			printf("%d ", i);
		}
	}
}

void read(unsigned int a[], int n, FILE *fp)
{
	unsigned int x;
	int base;
	int offset;

	fscanf(fp, "%d", &x);
	while(!feof(fp))
	{
		base = x / SIZE;
		offset = x % SIZE; 
		a[base] |= (0x01 << offset);

		fscanf(fp, "%d", &x);
	}
}
int main()
{
	int n = 1000000;
	unsigned int a[n / SIZE + 1]; // VLA : Variable Length Array
	// allocated dynamically
	// deallocated automatic
	FILE *fp = fopen("num.dat", "r");
	read(a, n, fp);
	disp(a, n);
	fclose(fp);
}
