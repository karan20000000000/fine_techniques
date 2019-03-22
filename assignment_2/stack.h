typedef struct stack
{
    int *arr;
    int n;
    int top;
} stack;

typedef struct element
{
    int val;
    stack * foughtWith;
} element;

stack * createStack(int n);
int push(stack *st, int val);
int pop(stack *st);
int isEmpty(stack *st);