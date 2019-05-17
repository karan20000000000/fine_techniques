#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	list_t l;
	FILE *fp;
	fp = fopen("mylist.dat", "a");
	fclose(fp);
	fp = fopen("mylist.dat", "r+");
	if(fp == NULL)
	{
		printf("error opening file\n"); exit(1);
	}
	
	init_list(&l, fp);
	int key;
	int opt;
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : scanf("%d", &key);
					 insert_key(&l, key);
					 break;
			case 2 : scanf("%d", &key);
					 delete_key(&l, key);
					 break;
			case 3 : disp_list(&l);
					 break;
		}
		scanf("%d", &opt);
	}
	#endif
	fclose(fp);
}
