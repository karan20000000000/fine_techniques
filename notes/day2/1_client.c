#include <stdio.h>
#include "1_list.h"

int main()
{
	list_t mylist;
	init(&mylist);
	int a[] = {20, 10, 40, 30, 25};
	int n = 5;
	
	for(int i = 0; i < n; ++i)
	{
		insert(&mylist, a[i]);
	}
	disp(&mylist);
}

