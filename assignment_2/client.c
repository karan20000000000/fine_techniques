#include <stdio.h>
#include <string.h>
#include "interface.h"

int main()
{
    char arr[10];

    printf("%d", (arr + 10) - (arr + 1));
}