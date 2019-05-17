#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define ALLOC(X) (X*)malloc(sizeof(X))

node_t* make_node(int key)
{
	node_t* temp = ALLOC(node_t);
	temp->key = key; temp->link = NULL;
}
void init_list(list_t *ptr_list, int n)
{
	ptr_list->head = ptr_list->mylist;
	ptr_list->n = n; 
	ptr_list->i = 0;
	
	
}
void add_at_end(list_t *ptr_list, int key)
{
	int i = ptr_list->i++;
	printf("add at end i : %d\n", i);
	ptr_list->mylist[i].key = key;
	ptr_list->mylist[i].link = NULL;
	if(i > 0)
	{
		ptr_list->mylist[i-1].link = &ptr_list->mylist[i];
	}
	
}
void disp_list(const list_t * ptr_list) 
{
	int i = ptr_list->i;
	node_t newone[MAX];
	for(int j = 0; j < i; ++j)
	{	
		long offset = ptr_list->mylist[j].link - ptr_list->mylist;
		printf("%d %p %ld %p\n", ptr_list->mylist[j].key, ptr_list->mylist[j].link,
					offset, newone + offset);
		
	}
	printf("\n");
}
#if 0
void write_file(const list_t *ptr_list, FILE* fp)
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		fprintf(fp, "%d ", temp->key);
		temp = temp->link;
	}
	printf("\n");
}
void read_file(list_t *ptr_list, FILE *fp)
{
	int key;
	fscanf(fp, "%d", &key);
	while(!feof(fp))
	{
		add_at_begin(ptr_list, key);
		fscanf(fp, "%d", &key);
	}
}

#endif










