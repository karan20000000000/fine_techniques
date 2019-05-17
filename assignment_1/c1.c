#include<stdio.h>
#include"a1.h"
void main()
{
	allocate(1000);
	
	char* p1 = (char*)mymalloc(50*sizeof(char));
	
	char* p2 = (char*)mymalloc(100*sizeof(char));
	
	char* p3 = (char*)mymalloc(500*sizeof(char));
	
	char* p4 = (char*)mymalloc(100*sizeof(char));
	
	display_mem_map();
	printf("\n");
	
	myfree(p4);
	
	display_mem_map();
	printf("\n");
	
	char* p5 = (char*)mymalloc(50*sizeof(char));
	
	display_mem_map();
	printf("\n");
	
	myfree(p5);

	myfree(p1);
	
	myfree(p2);
	
	display_mem_map();
	printf("\n");

	myfree(p3);
	
	display_mem_map();
	printf("\n");
}
