#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head = NULL;
	ptr_list->tail = NULL;
}

//void add_at_end(list_t *ptr_list, int key)
void add_at_end(list_t *ptr_list, const state_t* ptr_state)

{
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	//temp->key = key;
	temp->st = *ptr_state; 
	temp->next = temp->prev = NULL;

	if(ptr_list->tail == NULL)
	{
		temp->prev = temp->next = NULL;
		ptr_list->head = ptr_list->tail = temp;
	}
	else
	{
		temp->prev = ptr_list->tail;
		temp->next = NULL;
		ptr_list->tail = ptr_list->tail->next = temp;
	}
}
void remove_at_end(list_t *ptr_list)
{
	if(ptr_list->tail == NULL)
	{
		printf("empty list\n");
	}
	else  
	{
		node_t* temp = ptr_list->tail;
		//printf("removing %d\n", temp->key);
		disp_state(&temp->st);
		ptr_list->tail = ptr_list->tail->prev;	
		if(ptr_list->tail == NULL)
		{
			ptr_list->head = NULL;
		}
		else
		{
			ptr_list->tail->next = NULL;
		}
		free(temp);		
	}
}
void disp_list(const list_t *ptr_list)
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		//printf("%d ", temp->key);
		disp_state(&temp->st);
		temp = temp->next;
	}
}


int is_repeated(const list_t* ptr_list, const state_t* ptr_state)
{
	node_t* temp = ptr_list->head;
	int found = 0;
	while(temp && ! found)
	{
		found  = are_same(&temp->st, ptr_state);
		temp = temp->next;
	}
	return found;
}



