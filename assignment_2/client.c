#include <stdio.h>
#include <string.h>
#include "interface.h"

typedef struct blockinfo
{
    struct blockinfo * next;
    int size;
} blockinfo;

int main()
{
    char mem[100];

    blockinfo * p = (blockinfo *) mem;
    p->next = NULL;
    p->size = 100 - sizeof(blockinfo);

    printf("%p %p %d \n", p, p->next, p->size);
}