#include <stdio.h>
#include "a.h"

int main()
{
    allocate(1000);

    char *p1 = mymalloc(50);
    char *p2 = mymalloc(30);
    char *p3 = mymalloc(70);
    char *p4 = mymalloc(50);
    char *p5 = mymalloc(60);
    char *p6 = mymalloc(70);

    display_mem_map();

    myfree(p3); myfree(p5);

    display_mem_map();

    char *p7 = mymalloc(59);
    display_mem_map();

    printf("freeing\n");
    myfree(p7);
    display_mem_map();

    printf("%p\n", p);

    return 0;
}