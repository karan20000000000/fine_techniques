#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>

#include "interface.h"

#define lower 4
#define upper 500

void *ptr[100];
int main()
{
   // srand(time(0));

   int c = 0;

   srand(50);
   int n;

   display();
   while(getRemainingFreeMem() > 16)
   {
      n = (rand() % (upper - lower + 1)) + lower;
      void *p = mymalloc(n);

      if(p != NULL)
      { ptr[c++] = p; }
   }
   display();

   free(ptr[0]);

   display();

   free(ptr[2]);
   display();

   free(ptr[1]);
   display();

   return 0;
}