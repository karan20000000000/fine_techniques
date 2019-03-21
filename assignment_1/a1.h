#ifndef a1_h
#define a1_h

extern char *p;

void allocate(int n); //function to allocate memory for the global array p based on the value of n

void* mymalloc(int size); //function to allocate a block of size "size" from p

void myfree(void *p); //free the block pointed to by the parameter

void display_mem_map(); //display memory map in the following format
/*
starting_addr ending_addr allocated_bool
1 2 0
3 4 1
5 7 0
*/
//note that both the starting and ending addresses are inclusive 

void print_free_list(); //display free list in the format given below
/*
starting_addr block_size
1 2
5 3

please note that the free list will change depending on which allocation policy you are implementing.
*/

#endif
