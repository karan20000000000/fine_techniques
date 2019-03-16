#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "a1.h"

#define blksize sizeof(blockinfo)

typedef struct blockinfo
{
    struct blockinfo *next;
    int size; //indicates the size occupied by a block
    int idx;
} blockinfo;

char *mem;
int memsize;     //actual memory size
int userMemSize; //amt available to user

blockinfo *head;
int llc = 1;

void allocate(int n)
{
    userMemSize = n;
    memsize = n + (1000) * blksize; //one for the head
    mem = (char *)malloc(memsize * sizeof(char));

    head = (blockinfo *)(mem + userMemSize);
    head->next = NULL;
    head->size = 0;
    head->idx = 0;
}

static int getFreeMemAfter(blockinfo *p)
{
    int size = 0;

    if (p->next == NULL) //last node or head node
    {
        size = userMemSize - (p->idx + p->size);
    }
    else
    {
        size = p->next->idx - (p->idx + p->size);
    }

    return size;
}

static char *firstfit(int size) //return first free mem block
{
    blockinfo *temp = head;
    while (temp != NULL && getFreeMemAfter(temp) < size)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return NULL; //was unable to find a free memory block

    blockinfo *newblock = &head[llc++];
    newblock->idx = temp->idx + temp->size;
    newblock->next = temp->next;
    newblock->size = size;
    temp->next = newblock;

    return &mem[newblock->idx];
}

static char *bestfit(int size)
{
    blockinfo *temp = head;
    blockinfo *insertAfter = NULL;
    int mindiff = INT_MAX;

    while (temp != NULL)
    {
        int freemem = getFreeMemAfter(temp);
        int diff = freemem - size;
        if (diff >= 0 && diff < mindiff)
        {
            insertAfter = temp;
            mindiff = diff;
        }

        temp = temp->next;
    }

    if (insertAfter == NULL)
        return NULL;

    blockinfo *newblock = &head[llc++];
    newblock->idx = insertAfter->idx + insertAfter->size;
    newblock->next = insertAfter->next;
    newblock->size = size;
    insertAfter->next = newblock;

    return &mem[newblock->idx];
}

static char * worstfit(int size)
{
    blockinfo *temp = head;
    blockinfo *insertAfter = NULL;
    int maxdiff = 0;

    while (temp != NULL)
    {
        int freemem = getFreeMemAfter(temp);
        int diff = freemem - size;
        if (diff >= 0 && diff > maxdiff)
        {
            insertAfter = temp;
            maxdiff = diff;
        }

        temp = temp->next;
    }

    if (insertAfter == NULL)
        return NULL;

    blockinfo *newblock = &head[llc++];
    newblock->idx = insertAfter->idx + insertAfter->size;
    newblock->next = insertAfter->next;
    newblock->size = size;
    insertAfter->next = newblock;

    return &mem[newblock->idx];
}

void display_mem_map()
{
    blockinfo *temp = head;

    int s = getFreeMemAfter(head);
    if (s != 0)
    {
        printf("%d %d %d\n", 0, s - 1, 0);
    }

    temp = temp->next;
    while (temp != NULL)
    {
        printf("%d %d %d\n", temp->idx, temp->idx + temp->size - 1, 1);
        int m = getFreeMemAfter(temp);
        if (m != 0)
        {
            int sidx = temp->idx + temp->size;
            printf("%d %d %d\n", sidx, sidx + m - 1, 0);
        }

        temp = temp->next;
    }
}

void print_free_list()
{
    blockinfo *temp = head;

    int s = getFreeMemAfter(head);
    if (s != 0)
    {
        printf("%d %d\n", 0, s - 1);
    }

    temp = temp->next;
    while (temp != NULL)
    {
        int m = getFreeMemAfter(temp);
        if (m != 0)
        {
            int sidx = temp->idx + temp->size;
            printf("%d %d\n", sidx, sidx + m - 1);
        }

        temp = temp->next;
    }
}

void *mymalloc(int size)
{
    char *ret = NULL;
    ret = firstfit(size);

    return (void *)ret;
}

void myfree(void *p)
{
    blockinfo *temp = head->next;
    blockinfo *prev = head;
    //get the blockinfo ptr that corresponds to block p points to
    while (temp != NULL)
    {
        if (&mem[temp->idx] == p)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
}