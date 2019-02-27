#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h> 
#include "interface.h"

#define lower 4
#define upper 500

int main()
{
   // srand(time(0));
   srand(50);
   int n;

   display();
   while(getRemainingFreeMem() > 16)
   {
      n = (rand() % (upper - lower + 1)) + lower;
      mymalloc(n);
      display();
   }
}