#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define ALLOC(X) (X*)malloc(sizeof(X))

node_t* make_node(int key)
{
	node_t* temp = ALLOC(node_t);
	temp->key = key; temp->link = NULL;
}
void init_list(list_t *ptr_list)
{
	ptr_list->head = NULL;
}
void add_at_begin(list_t *ptr_list, int key)
{
	node_t* temp = make_node(key);
	temp->link = ptr_list->head;
	ptr_list->head = temp;
}
void disp_list(const list_t * ptr_list) 
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		printf("%d ", temp->key);
		temp = temp->link;
	}
	printf("\n");
}

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












