#include <string.h>
#include <stdio.h>

#define memsize 50
#define blksize sizeof(blockinfo)

char *firstfit(int);
char *bestfit(int);
char *worstfit(int);

int policy = 1;
char *(*policyfun)(int);

typedef struct blockinfo
{
    struct blockinfo *next;
    int size; //indicates the size occupied by a block
} blockinfo;

char mem[memsize]; //to accomodate initial two things for bookkeeping and housekeeping

blockinfo *head; //may not start from the beginnning but initially its in the beginning

int getidx(char *ptr) //get index of char *
{
    return ptr - mem;
}

int getFreeMemAfter(blockinfo *p) //gets the free memory after a block
{
    //either the next is null or there is a next pointer

    //TODO: check for +-1 error

    if (p->next == NULL) //only node or last node
    {
        return memsize - (getidx(p) + blksize + p->size);
    }
    else
    {
        return getidx(p->next) - (getidx(p) + blksize + p->size);
    }
}

void setblockpointer(int idx, int size)
{
    blockinfo *p = (blockinfo *)(mem + idx);
    p->next = NULL;
    p->size = size;

    blockinfo *temp = head;
    blockinfo *q = NULL;
    while (temp != NULL && getidx(temp) < idx)
    {
        q = temp;
        temp = temp->next;
    }
}

void * mymalloc(int size)
{
    char *ret = policyfun(size);
}

// void free(void *)
// {

// }

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
        // policyfun = bestfit;
    }
    else if (strcmp(pol, "worst") == 0)
    {
        policy = 3;
        // policyfun = worstfit;
    }
}

char *getpolicy()
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
        head->size = 50;
    }
    blockinfo *temp = head;

    while (temp != NULL)
    {
        printf("%p | %d ...\t", temp->next, temp->size);
        temp = temp->next;
    }
    printf("\n");
}

char * firstfit(int size)   //return first free mem block
{
    blockinfo *temp = head;
    while(temp != NULL && getFreeMemAfter(temp) < (size + blksize))
    {
        temp = temp->next;
    }

    if(temp == NULL) return NULL;   //was unable to find a free memory block

    blockinfo *newblock = (blockinfo *) (temp + blksize + temp->size);
    newblock->next = temp->next;
    newblock->size = size;
    temp->next = newblock;

    return (char *) (newblock + blksize);
}


int main()
{
    display();
    char * t = firstfit(20);
    display();
}