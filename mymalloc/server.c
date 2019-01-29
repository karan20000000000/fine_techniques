#include <stdlib.h>

static void * book[100];
static int bookcount = 0;

void * mymalloc(unsigned int size)
{

    void *p = malloc(size);

    book[bookcount++] = p;
    showbook();
    return p;
}

void showbook()
{
    for(int i=0; i<bookcount; i++)
    {
        printf("%p\t%d\n", book[i], i);
    }
    printf("\n");
}

void myfree(void *ptr)
{

    printf("Trying to free %p\n", ptr);
    for(int i=0; i<bookcount; i++)
    {
        if(book[i] == ptr)
        {
            free(book[i]);
            printf("free-ed %p\n", book[i]);
            book[i] = NULL;
            break;
        }
    }
}