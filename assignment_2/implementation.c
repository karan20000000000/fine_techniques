#include <string.h>

#define memsize 1000
int policy = 1;

typedef struct blockinfo
{
    struct blockinfo * next;
    int size;   //indicates the size occupied by a block
} blockinfo;


char mem[memsize+sizeof(blockinfo)];     //to accomodate initial two things for bookkeeping and housekeeping

blockinfo *head;    //may not start from the beginnning but initially its in the beginning


void setblockpointer(int idx, int size)
{
    blockinfo *p = (blockinfo *) (mem+idx);
    p->next = NULL;
    p->size = size;
}



// void* mymalloc(int)
// {
    
// }

// void free(void *)
// {

// }

void setpolicy(char *pol)
{
    if(strcmp(pol, "first") == 0)
    {  policy = 1;  }
    else if(strcmp(pol, "best") == 0)
    {  policy = 2;  }
    else if(strcmp(pol, "worst") == 0)
    {  policy = 3;  }
}

char * getpolicy()
{
    switch(policy)
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
    if(head == NULL)
    {
        head = (blockinfo *) mem;
        head->next = NULL;
        head->size = memsize;
    }
    blockinfo *temp = head;
    while(temp!=NULL)
    {
        printf("%p | %d ...\t", temp->next, temp->size);
    }
    printf("\n");
}