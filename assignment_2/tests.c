#include <stdio.h>
#include <string.h>
#include "interface.h"

void display();

int main()
{
   int *arr = (int *) mymalloc(34);
   display();
}