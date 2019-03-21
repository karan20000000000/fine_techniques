#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <signal.h>

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


//creates a ragged 2d array of size n
int ** getBCountArr(int n)
{
   int **temp = (int **) malloc(n * sizeof(int *));
   for(int i=0; i<n; i++)
   {
       temp[i] = (int *) calloc((i+1), sizeof(int));
   }

   return temp;
}

void dispBCountArr(int **bc, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            printf("%d\t", bc[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void makeEmpty(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = 0;
    }
}

int findSecondLargest(int *a, int n)
{
    int s = log2(n) + 1;
    printf("%d %d\n", n, s);
    int **bCountArr;
    bCountArr = getBCountArr(s);
    dispBCountArr(bCountArr, s);

    int compArr[n];
    int compIdx = -1;

    for(int i=0; i<n; i++)
    {
        // if(a[i] == 2)
        // { raise(SIGINT);  }
        if(bCountArr[0][0] == 0)    //if there's no one to fight then put the element in first position
        {
            bCountArr[0][0] = a[i];
        }
        else
        {
            //make em fight and check higher levels
            if(bCountArr[0][0] > a[i])
            {
                compArr[++compIdx] = bCountArr[0][0];
                compArr[++compIdx] = a[i];
            }
            else
            {
                compArr[++compIdx] = a[i];
                compArr[++compIdx] = bCountArr[0][0];
            }

            //cleanup [0][0]
            bCountArr[0][0] = 0;
            
            for(int j=1; j<s; j++)  //bCountArr[j] has j+1 elements
            {
                //fill bCountArr[j] with compArr, if bCountArr[j] is empty, reset compArr and break
                if(bCountArr[j][0] == 0)
                {
                    for(int k=0; k < j+1; k++)
                    {  bCountArr[j][k] = compArr[k];  }
                    compIdx = -1;
                    break;
                }
                else
                {
                    //compare bCountArr[j][0] with compArr, and accordingly empty out bCountArr[j]
                    if(bCountArr[j][0] > compArr[0])    //case if bcount arr already has greater element
                    {
                        //copy bCountArr[j] to compArr and add compArr[0] to that, also make bCountArr[j] 0
                        int less = compArr[0];
                        for(int k=0; k < j+1; k++)
                        {
                            compArr[k] = bCountArr[j][k];
                            bCountArr[j][k] = 0;
                        }
                        compArr[++compIdx] = less;
                    }
                    else
                    {
                        compArr[++compIdx] = bCountArr[j][0];
                        //reset/empty out bCountArr[j]
                        makeEmpty(bCountArr[j], j+1);
                    }
                    
                }
                
            }

        }
        // dispBCountArr(bCountArr, s);
    }

    //now to find 2nd max in the last row: bCountArr[s-1]
    int max = bCountArr[s-1][1];
    for(int i=2; i<s; i++)
    {
        if(bCountArr[s-1][i] > max)
        { max = bCountArr[s-1][i];  }
    }

    return max;
}