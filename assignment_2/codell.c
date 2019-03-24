#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <signal.h>

#include "codell.h"

int findSecondLargest(int *a, int n);

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    int num = findSecondLargest(a, n);

    printf("%d\n", num);
}

linkedlist * getBCountArr(int n)
{
    linkedlist *temp = (linkedlist *) malloc(n * sizeof(linkedlist));
    for(int i=0; i<n; i++)
    {
        init_list(&temp[i]);
    }

    return temp;
}

void dispBCountArr(linkedlist *bc, int n)
{
    for(int i=0; i<n; i++)
    {
        disp_list(&bc[i]);
    }
}

int findSecondLargest(int *a, int n)
{
    int s = log2(n) + 1;
    printf("%d %d\n", n, s);
    linkedlist *bcarr;      //binary counter arr
    bcarr = getBCountArr(s);

    linkedlist compared;
    init_list(&compared);

    for(int i=0; i<n; i++)
    {
        if(is_empty(&bcarr[0])) //if first slot is empty, 
        {
            insert_beg(&bcarr[0], a[i]);
        }
        else
        {
            if(bcarr[0].head->data > a[i])  //if what we have in slot 0 is greater
            {
                insert_beg(&compared, bcarr)
            }
        }
        
    }
}