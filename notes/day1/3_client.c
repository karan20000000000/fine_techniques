#include <stdio.h>
#include "3_fn.h"

int main()
{
//	printf("%d\n", ABCD);
	foo();
}

#if 0
void foo()
{
}
#endif
// linker errors:
// 1. unresolved external
// 2. multiple definition
// provide a #define on the command line
// gcc -DABCD=111 -c 3_client.c
