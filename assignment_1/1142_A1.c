#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "a.h"

#define blksize sizeof(blockinfo)

typedef struct blockinfo
{
    struct blockinfo *next;
    int size; //indicates the size occupied by a block
    int occupied;
} blockinfo;

char *mem;
char *p;    //the global p
int memsize;

blockinfo *head;

void allocate(int n)
{
    memsize = n;
    mem = (char *)malloc(memsize * sizeof(char));
    p = mem;

    //initialize the head pointer in the memory array
    head = (blockinfo *)mem;
    head->next = NULL;
    head->size = n - blksize;
    head->occupied = 0;
}

static int getidx(blockinfo *ptr) //get index in mem array of blockinfo *
{
    // return ptr - (blockinfo *)mem;
    return (char *)ptr - mem;
}

static char *bestfit(int size)
{
    //this method finds the min diff between size and free mem of a block, and finds the block with the least diff

    blockinfo *temp = head;
    blockinfo *insertAt = NULL;
    int mindiff = INT_MAX;

    //find the block with tightest bound of free space with the size the user wants
    while (temp != NULL)
    {
        int freemem = temp->size;

        if (!temp->occupied)
        {
            int diff = freemem - size;
            if (diff >= 0 && diff < mindiff)
            {
                insertAt = temp;
                mindiff = diff;
            }
        }

        temp = temp->next;
    }

    if (insertAt == NULL)
        return NULL;

    insertAt->occupied = 1;
    insertAt->size = size;

    //if the difference between insertAt->next and the newly allocated node insertAt is > blksize then make a new node
    int sizediff = 0;

    //first find out if there's a node after current one, or are we at the end
    if (insertAt->next != NULL)
    {
        sizediff = ( (char *) insertAt->next - ( (char *) insertAt + blksize + insertAt->size));
    }
    else
    {
        sizediff = memsize - 1 - (getidx(insertAt) + blksize + insertAt->size);
    }

    //make new node if there's space
    if (sizediff > blksize)
    {
        blockinfo *nextNode = (blockinfo *)((char *)insertAt + blksize + insertAt->size);
        nextNode->next = insertAt->next;
        nextNode->occupied = 0;
        nextNode->size = sizediff - blksize + 1;

        insertAt->next = nextNode;
    }

    return ((char *)insertAt + blksize);
}

void* mymalloc(int size)
{
    char *ret = bestfit(size);

    return (void *) ret;
}

void myfree(void *p)
{
    blockinfo *blk = (blockinfo *)((char *)p - blksize);

    //taking care of extremities
    if (blk <= head)
        return;

    int idx = getidx(blk);
    if (idx >= memsize)
        return;

    blk->occupied = 0;

    //merge free blocks after this
    blockinfo *after = blk->next;

    //when we have some empty space b/w this node and next node, and we don't a block structure in the middle, we need to take care of the wasted memory
    if(after == NULL)
    {
        blk->size += memsize - 1 - (getidx(blk) + blksize + blk->size);
    }
    else
    {
        blk->size += getidx(after) - (getidx(blk) + blksize + blk->size);
    }
    
    //coerce the blocks after the current freed block
    while (after != NULL && !after->occupied)
    {
        blk->next = after->next;
        blk->size += after->size + blksize;
        after = after->next;
    }

    //merge if the block before this is unoccupied as well
    blockinfo *temp = head;
    while (temp != NULL && temp->next != blk)
    {
        temp = temp->next;
    }
    if (!temp->occupied)
    {
        temp->size += blksize + blk->size;
        temp->next = blk->next;
    }
}

void print_book()
{
    printf("%ld\n%ld\n", blksize, blksize);
}

void display_mem_map()
{
    blockinfo *temp = head;
    while (temp != NULL)
    {
        printf("%d\t%ld\tbook\n", getidx(temp), blksize);
        if (temp->occupied)
        {
            printf("%ld\t%d\tallocated\n", getidx(temp) + blksize, temp->size);
        }
        else
        {
            printf("%ld\t%d\tfree\n", getidx(temp) + blksize, temp->size);
        }

        temp = temp->next;
    }
}




int main()
{
    allocate(1000);


    char *p1 = mymalloc(50);
    char *p2 = mymalloc(30);
    char *p3 = mymalloc(70);
    char *p4 = mymalloc(50);
    char *p5 = mymalloc(60);
    char *p6 = mymalloc(70);

/*
    display_mem_map(); printf("\n");

    myfree(p3); myfree(p5);

    display_mem_map(); printf("\n");

    char *p7 = mymalloc(59);
    display_mem_map(); printf("\n");

    printf("freeing\n");
    myfree(p7);
    display_mem_map(); printf("\n");

    // printf("%p\n", p);
*/

    display_mem_map(); printf("\n");
    myfree(p4);
    display_mem_map(); printf("\n");
    myfree(p3);
    display_mem_map(); printf("\n");
    myfree(p2);
    display_mem_map(); printf("\n");

    myfree(p5);
    display_mem_map(); printf("\n");


    return 0;
}


