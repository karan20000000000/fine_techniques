#include<stdio.h>
#include<stdlib.h>
#include "a2.h"

void main()
{
    int length;
    int *numbers;
    int temp;
    FILE * fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d", &length);
    numbers = (int *)malloc(sizeof(int)*length);
    for(int i = 0; i<length; i++)
    {
        fscanf(fptr, "%d", &numbers[i]);
    }
    fclose(fptr);
    
    sec_big(numbers, length);
}
