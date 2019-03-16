#include <stdio.h>
#include "a1.h"
void main()
{
#if 0
	allocate(10);
	char *p = (char *)mymalloc(2 * sizeof(char));
	display_mem_map();
	printf("\n");
	char *q = (char *)mymalloc(5 * sizeof(char));
	display_mem_map();
	printf("\n");
	char *r = (char *)mymalloc(4 * sizeof(char));
	display_mem_map();
	printf("\n");
	myfree(p);
	display_mem_map();
	printf("\n");
	myfree(q);
	display_mem_map();
	printf("\n");
#endif

	allocate(20);
	char *p = (char *)mymalloc(10);
	char *q = (char *)mymalloc(5);
	char *r = (char *)mymalloc(5);
	display_mem_map();
	printf("\n");
	myfree(q);

	char *s = (char *)mymalloc(4);

	display_mem_map();
	printf("\n");
}
