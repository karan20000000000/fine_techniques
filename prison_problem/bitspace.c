#include <stdio.h>
#include <signal.h>

#define arrsize 4

void setbit(int *a, int n)
{
    *a = (*a) | (1 << n);
}

void unsetbit(int *a, int n)
{
    *a = (*a) & ~(1 << n);
}

int checkset(int a, int n)
{
    return a & (1 << n) != 0;
}

void close_all(int *a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int idx = i / 32;
        int bitnum = i % 32;
        setbit(&a[idx], bitnum);
        printf("%d %d %d\n", idx, bitnum , i);
    }
}

void disp_open(int *a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int idx = i / 32;
        int bitnum = i % 32;
        if (checkset(a[idx], bitnum))
        {
            printf("%d ", i);
        }

    }

    printf("\n");
}

void open_and_close(int *a, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            int idx = j / 32;
            int bitnum = j % 32;

            if(checkset(a[idx], bitnum))
            {
                unsetbit(&a[idx], bitnum);
            }
            else
            {
                setbit(&a[idx], bitnum);
            }
            
        }
    }
}

int main()
{
    int arr[arrsize];
    int n;
    scanf("%d", &n);

    // raise(SIGINT);
    close_all(arr, n);
    disp_open(arr, n);
    open_and_close(arr, n);
}