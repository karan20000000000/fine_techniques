#include <stdio.h>
#include "list.h"
#include <stdlib.h>

int main()
{
	int a[] = {22, 11, 44, 55, 33};
	
	int n = 5;
	list_t l;
	init_list(&l, n);
	for(int i = 0; i < n; ++i)
	{
		add_at_end(&l, a[i]);
	}
	disp_list(&l);
	#if 0
	FILE *fp1 = fopen("list.dat", "w");
	write_file(&l, fp1);
	fclose(fp1);
	FILE *fp2 = fopen("list.dat", "r");
	list_t newlist;
	init_list(&newlist);
	read_file(&newlist, fp2);
	disp_list(&newlist);
	#endif
}
