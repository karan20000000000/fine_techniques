#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "a1.h"

#define blksize sizeof(blockinfo)

char *worstfit(int);

typedef struct blockinfo
{
    struct blockinfo *next;
    int size; //indicates the size occupied by a block
} blockinfo;

char *mem;
int memsize;
blockinfo *head;

void allocate(int n)
{
    mem = (char *)malloc(n * sizeof(char));
    memsize = n;
}

int getidx(blockinfo *ptr) //get index of blockinfo * in the mem array
{
    // return ptr - (blockinfo *)mem;
    return (char *)ptr - mem;
}

int getFreeMemAfter(blockinfo *p) //gets the free memory after a block
{
    //either the next is null or there is a next pointer

    int size;

    if (p->next == NULL) //only node or last node
    {
        size = memsize - (getidx(p) + blksize + p->size);
    }
    else
    {
        size = getidx(p->next) - (getidx(p) + blksize + p->size);
    }

    if (size < 0)
    {
        size = 0;
    }

    return size;
}

void *mymalloc(int size)
{
    char *ret = NULL;
    if (head == NULL)
    {
        head = (blockinfo *)mem;
        head->next = NULL;
        head->size = 0;
    }
    ret = worstfit(size);

    return (void *)ret;
}

void myfree(void *p)
{
    //go back from p's location to get a possible blockinfo struct location
    blockinfo *blk = (blockinfo *)((char *)p - blksize);

    if (blk <= head)
        return;

    int idx = getidx(blk);
    if (idx >= memsize)
        return;

    blk->size = 0; //seems redundant

    blockinfo *temp = head;
    while (temp != NULL && temp->next != blk)
    {
        temp = temp->next;
    }
    temp->next = blk->next;
}

char *worstfit(int size)
{
    blockinfo *temp = head;
    blockinfo *insertAfter = NULL;
    int maxdiff = 0;

    while (temp != NULL)
    {
        int freemem = getFreeMemAfter(temp);
        int diff = freemem - (size + blksize);
        if (diff >= 0 && diff > maxdiff)
        {
            insertAfter = temp;
            maxdiff = diff;
        }

        temp = temp->next;
    }

    if (insertAfter == NULL)
        return NULL;

    blockinfo *newblock = (blockinfo *)((char *)insertAfter + blksize + insertAfter->size);
    newblock->next = insertAfter->next;
    newblock->size = size;
    insertAfter->next = newblock;

    return ((char *)newblock + blksize);
}

void display_mem_map()
{
    blockinfo *temp = head;

    while (temp != NULL)
    {

        printf("%d %d %d\n", getidx(temp), getidx(temp) + blksize + temp->size - 1, 1);
        int m = getFreeMemAfter(temp);
        if (m != 0)
        {
            if (temp->next == NULL)
            {
                printf("%d %d %d\n", getidx(temp) + blksize + temp->size, memsize - 1, 0);
            }
            else
            {
                printf("%d %d %d\n", getidx(temp) + blksize + temp->size, getidx(temp->next) - 1, 0);
            }
        }

        temp = temp->next;
    }
}

void print_free_list()
{
    blockinfo *temp = head;

    while (temp != NULL)
    {
        int m = getFreeMemAfter(temp);
        if (m != 0)
        {
            printf("%d %d\n", getidx(temp) + blksize + temp->size, m);
        }

        temp = temp->next;
    }
}

// int main()
// {
//     allocate(100);
//     int *a1 = mymalloc(10);
//     int *a2 = mymalloc(3);
//     int *a3 = mymalloc(5);
//     display_mem_map();

//     myfree(a1);
//     display_mem_map();

//     myfree(a3);
//     display_mem_map();

//     print_free_list();
// }