#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[5] = {11, 22, 33, 44, 55};
	int i = 5;
	// a[i] = 111; // undefined behaviour
	// dereferencing a dangling pointer fails only when there is no physical location
	
	int *p;
	{
		p = (int*)malloc(sizeof(int));	
		*p = 10;
		free(p);
		int *q = (int*)malloc(sizeof(int) * 5);	
		 
		free(q);
	}
	
}
