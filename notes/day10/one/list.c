#include <stdio.h>
#include <stdlib.h>
#include "list.h"



void init_list(list_t *ptr_list)
{
	ptr_list->head = NULL;
}
void disp_list(const list_t *ptr_list)
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		printf("%d ", temp->key);
		temp = temp->link;
	}
	printf("\n");
}
void insert_key(list_t *ptr_list, int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key = key; temp->link = NULL;

	if(ptr_list->head == NULL)
	{
		ptr_list->head = temp;
	}
	else
	{
		node_t* prev = NULL; node_t* pres = ptr_list->head;
		while(pres != NULL && pres->key < temp->key)
		{
			prev = pres;
			pres = pres->link;	
		}
		if(prev == NULL)
		{	
			ptr_list->head = temp;
		}
		else
		{
			prev->link = temp;
		}
		temp->link = pres;
	}



}

void delete_key(list_t *ptr_list, int key)
{
	node_t* pres = ptr_list->head;
	node_t* prev = NULL;
	while(pres != NULL && pres->key != key)
	{
		prev = pres;
		pres = pres->link;
	}
	if(pres == NULL)
	{
		printf("key %d not found\n", key);
	}
	else if(prev != NULL)
	{
		prev->link = pres->link;
	}
	else
	{
		ptr_list->head = pres->link;
	}
	free(pres);

}













