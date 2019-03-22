#include <stdlib.h>
#include "stack.h"

stack * createStack(int n)
{
    stack *newStack = (stack *) malloc(sizeof(stack));
    newStack->n = n;
    newStack->arr = (int *) malloc(n*sizeof(int));
    newStack->top = -1;
}

int push(stack *st, int val)
{
    if(st->top == st->n - 1)
    {  return -1;   }
    st->arr[++st->top] = val;
}

int pop(stack *st)
{
    if(st->top == -1)
    {  return -1;  }
    int v = st->arr[st->top];
    (st->top)--;
    return v;
}

int isEmpty(stack *st)
{
    return st->top == -1;
}