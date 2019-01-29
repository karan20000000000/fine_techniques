#include <stdio.h>
#include "header.h"

int main()
{
    int *p = (int *) malloc(5*sizeof(int));
    int *q = (int *) malloc(5*sizeof(int));
    free(p);
    int *r = (int *) malloc(5*sizeof(int));
    int *s = (int *) malloc(5*sizeof(int));
    int *t = (int *) malloc(5*sizeof(int));

    

}