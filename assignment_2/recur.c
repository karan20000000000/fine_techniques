#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <signal.h>

#include "stack.h"

int findSecondLargest(int *a, int n);
element * pairFight(element *arr, int n, int l, int r);

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

int findSecondLargest(int *a, int n)
{
    //create an element arr of size n
    element *arr = (element *) malloc(n * sizeof(element));
    int ssize = log2(n);
    for(int i=0; i<n; i++)
    {
        arr[i].val = a[i];
        arr[i].foughtWith = createStack(ssize);
    }

    element *g = pairFight(arr, n, 0, n-1);

    //find largest element in g's stack's arr
    int max = g->foughtWith->arr[0];
    for(int i=0; i<g->foughtWith->n; i++)
    {
        if(g->foughtWith->arr[i] > max)
        {
            max = g->foughtWith->arr[i];
        }
    }

    return max;
}

//make em fight in pairs
//for the element that wins, add the loser element's val to other's stack
//free the loser's stack
element * pairFight(element *arr, int n, int l, int r)
{
    if(l == r - 1)
    {
        // printf("%d %d\n", arr[l].val, arr[r].val);
        if(arr[l].val > arr[r].val)
        {
            push(arr[l].foughtWith, arr[r].val);
            free(arr[r].foughtWith);

            return &arr[l];
        }
        else
        {
            push(arr[r].foughtWith, arr[l].val);
            free(arr[l].foughtWith);

            return &arr[r];
        }
    }
    else
    {
        int m = (l+r)/2;
        element *leftside = pairFight(arr, n, l, m);
        element *rightside = pairFight(arr, n, m+1, r);
        if(leftside->val > rightside->val)
        {
            push(leftside->foughtWith, rightside->val);
            free(rightside->foughtWith);

            return leftside;
        }
        else
        {
            push(rightside->foughtWith, leftside->val);
            free(leftside->foughtWith);

            return rightside;
        }
    }
    
}