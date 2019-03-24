#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <signal.h>

#include "codenode.h"

int findSecondLargest(int *a, int n);

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int num = findSecondLargest(a, n);

    printf("\n%d\n", num);
}

node **getBCountArr(int n)
{
    node **temp = (node **)malloc(n * sizeof(node *));
    for (int i = 0; i < n; i++)
    {
        temp[i] = NULL;
    }

    return temp;
}

void dispBCountArr(node **bc, int n)
{
    for (int i = 0; i < n; i++)
    {
        disp_list(bc[i]);
        printf("\n");
    }
}

int find_largest(node *p)
{
    if (p == NULL)
    {
        return -1;
    }
    int l = p->data;
    node *temp = p->next;
    while (temp != NULL)
    {
        if (temp->data > l)
        {
            l = temp->data;
        }
        temp = temp->next;
    }

    return l;
}

int findSecondLargest(int *a, int n)
{
    int s;
    s = ceil(log2(n)) + 1;
    // printf("%d %d\n", n, s);
    node **bcarr;
    bcarr = getBCountArr(s);
    // dispBCountArr(bcarr, s);

    node *compList = NULL;

    for (int i = 0; i < n; i++)
    {
        // if(a[i] == 17)
        // {  raise(SIGINT);  }
        if (bcarr[0] == NULL)
        {
            insert_beg(&bcarr[0], a[i]);
        }
        else
        {
            compList = bcarr[0];
            //fight here
            printf("%d x %d = ", bcarr[0]->data, a[i]);
            if (bcarr[0]->data > a[i])
            {
                printf("%d %d\n", bcarr[0]->data, a[i]);
                insert_beg(&compList, a[i]);
            }
            else
            {
                printf("%d %d\n", a[i], bcarr[0]->data);
                insert_head(&compList, a[i]);
            }

            bcarr[0] = NULL;

            for (int j = 1; j < s; j++)
            {
                if (bcarr[j] == NULL) //if the next slot is empty, then just put the compList here
                {
                    bcarr[j] = compList;
                    compList = NULL;
                    break;
                }
                else
                {
                    //fight here
                    disp_list(bcarr[j]);
                    printf("x ");
                    disp_list(compList);
                    printf("= ");
                    if (bcarr[j]->data > compList->data)
                    {

                        //now we just need the first element from compList
                        int v = compList->data;
                        compList = bcarr[j];
                        insert_beg(&compList, v);
                    }
                    else
                    {
                        insert_beg(&compList, bcarr[j]->data);
                    }
                    bcarr[j] = NULL; //empty out bcarr[j], TODO: free it

                    disp_list(compList);
                    printf("\n");
                }
            }
        }

        // dispBCountArr(bcarr, s);
    }

    //TODO: check bcarr for non 2^n possiblities
    if ((n & (n - 1)) != 0)
    {
        //make sure we merge and get all elements to last column bcarr[s-1]
        while (bcarr[s - 1] == NULL)
        {
            for (int i = 0; i < s; i++)
            {
                if (i == s - 1)
                {
                    //make sure to put back compList here
                    if (compList == NULL)
                    {
                        printf("Something wrong\n");
                    }

                    bcarr[i] = compList;
                    compList = NULL;
                }
                else if (bcarr[i] != NULL)
                {
                    if (compList == NULL)
                    {
                        compList = bcarr[i];
                        bcarr[i] = NULL;
                    }
                    else
                    {
                        //make bcarr[i] and compList fight
                        disp_list(bcarr[i]);
                        printf("x ");
                        disp_list(compList);
                        printf("= ");
                        if (bcarr[i]->data > compList->data)
                        {
                            //now we just need the first element from compList
                            int v = compList->data;
                            compList = bcarr[i];
                            insert_beg(&compList, v);
                        }
                        else
                        {
                            insert_beg(&compList, bcarr[i]->data);
                        }
                        bcarr[i] = NULL; //empty out bcarr[i], TODO: free it
                        disp_list(compList);
                        printf("\n");
                    }
                }
            }
        }
    }

    int secondLargest = find_largest(bcarr[s - 1]->next);

    return secondLargest;
}