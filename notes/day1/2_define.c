#include <stdio.h>
#define what 100
int main()
{
	#define what1 200
	printf("what : %d\n", what);
	{
		#define what 300
		printf("what : %d\n", what);
	}
	printf("what : %d\n", what);
	
	printf("what1 : %d\n", what1);
	return 0;
}
