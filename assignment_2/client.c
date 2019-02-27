#include <stdio.h>
#include <string.h>
#include "interface.h"

int main()
{
    int accepting = 1;
    int option;
    while(accepting)
    {
        printf("Enter option: \n");
        printf("1: Get memory\n");
        printf("2: Free memory\n");
        printf("3: Change policy\n");
        printf("4: End\n");
        display();
        printf("Total free mem: %d\n",getRemainingFreeMem());

        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter size\n");
                int size;
                scanf("%d", &size);
                mymalloc(size);
                break;
            case 2:
                break;
            case 3:
                printf("Enter policy\n");
                char str[10];
                scanf("%s", str);
                setpolicy(str);
            case 4:
                accepting = 0;
        }
    }
}