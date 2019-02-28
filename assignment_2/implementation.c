#include <string.h>
#include <stdio.h>
#include <limits.h>

#define memsize 10000
#define blksize sizeof(blockinfo)

char *firstfit(int);
char *bestfit(int);
char *worstfit(int);

int policy = 1;
char *(*policyfun)(int) = firstfit;

typedef struct blockinfo
{
    struct blockinfo *next;
    int size; //indicates the size occupied by a block
} blockinfo;

char mem[memsize]; //to accomodate initial two things for bookkeeping and housekeeping

blockinfo *head; //may not start from the beginnning but initially its in the beginning

int getidx(blockinfo *ptr) //get index of blockinfo *
{
    // return ptr - (blockinfo *)mem;
    return (char *) ptr - mem;
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
    ret = policyfun(size);

    return (void *)ret;
}

void free(void *p)
{
    //go back from p's location to get a possible blockinfo struct location
    blockinfo *blk = (blockinfo *) ((char *) p - blksize);

    if(blk <= head) return;

    int idx = getidx(blk);
    if(idx >= memsize) return;
    
    blk->size = 0;  //seems redundant

    blockinfo *temp = head;
    while(temp != NULL && temp->next != blk)
    {
        temp = temp->next;
    }
    temp->next = blk->next;
}

void setpolicy(char *pol)
{
    if (strcmp(pol, "first") == 0)
    {
        policy = 1;
        policyfun = firstfit;
    }
    else if (strcmp(pol, "best") == 0)
    {
        policy = 2;
        policyfun = bestfit;
    }
    else if (strcmp(pol, "worst") == 0)
    {
        policy = 3;
        policyfun = worstfit;
    }
}

char * getpolicy()
{
    switch (policy)
    {
    case 1:
        return "first";
    case 2:
        return "best";
    case 3:
        return "worst";
    }
}

void display()
{
    if (head == NULL)
    {
        head = (blockinfo *)mem;
        head->next = NULL;
        head->size = 0;
    }
    blockinfo *temp = head;

    while (temp != NULL)
    {
        printf("%d | %d | ... | %d\t %p -> ", getidx(temp), temp->size, getFreeMemAfter(temp),temp->next);
        temp = temp->next;
    }
    printf("\nRemaining free total: %d\n", getRemainingFreeMem());
}

char * firstfit(int size) //return first free mem block
{
    blockinfo *temp = head;
    while (temp != NULL && getFreeMemAfter(temp) < (size + blksize))
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return NULL; //was unable to find a free memory block

    blockinfo *newblock = (blockinfo *)((char *) temp + blksize + temp->size);
    newblock->next = temp->next;
    newblock->size = size;
    temp->next = newblock;

    return ((char *) newblock + blksize);
}

char * bestfit(int size)
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
        }

        temp = temp->next;
    }

    if (insertAfter == NULL)
        return NULL;

    blockinfo *newblock = (blockinfo *)((char *) insertAfter + blksize + insertAfter->size);
    newblock->next = insertAfter->next;
    newblock->size = size;
    insertAfter->next = newblock;

    return ((char *) newblock + blksize);
}

char * worstfit(int size)
{
    blockinfo *temp = head;
    blockinfo *insertAfter = NULL;
    int mindiff = 0;

    while (temp != NULL)
    {
        int freemem = getFreeMemAfter(temp);
        int diff = freemem - size;
        if (diff >= 0 && diff > mindiff)
        {
            insertAfter = temp;
            mindiff = diff;
        }

        temp = temp->next;
    }

    if (insertAfter == NULL)
        return NULL;

    blockinfo *newblock = (blockinfo *)((char *) insertAfter + blksize + insertAfter->size);
    newblock->next = insertAfter->next;
    newblock->size = size;
    insertAfter->next = newblock;

    return ((char *) newblock + blksize);
}

int getRemainingFreeMem()
{
    int size = 0;
    blockinfo *temp = head;
    while(temp != NULL)
    {
        size += getFreeMemAfter(temp);
        temp = temp->next;
    }

    return size;
}

// int main()
// {
//     int *arr = mymalloc(34);
//     display();
// }