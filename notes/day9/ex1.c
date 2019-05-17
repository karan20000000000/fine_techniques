#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int a = 100;
int main()
{
	srand(getpid());
	printf("a : %d ptr to a : %p\n", a, &a);
	sleep(5);
	a = rand()%100;
	printf("a : %d ptr to a : %p\n", a, &a);
}
