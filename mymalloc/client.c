#include <stdio.h>
#include "stdlib.h"
#include "header.h"

int main()
{
    int *p = (int *) malloc(5*sizeof(int));
    int *q = (int *) malloc(5*sizeof(int));
    free(p);
    free(q);
    free(p);
    free(q);


    int *r = (int *) malloc(5*sizeof(int));
    int *s = (int *) malloc(5*sizeof(int));
    int *t = (int *) malloc(5*sizeof(int));
    free(q); //no error but it frees r!
    free(r); //free(q) above frees r!
    free(t);
}