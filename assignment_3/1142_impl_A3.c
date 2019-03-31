#include <stdio.h>
#include <stdlib.h>
#include "1142_header_A3.h"

//initializes a state to 8 0 0
void init_state(state_t *ptr_state)
{
    ptr_state->eightV = 8;
    ptr_state->fiveV = 0;
    ptr_state->threeV = 0;

    ptr_state->fn_index = 0;
}


void disp_state(const state_t *ptr_state)
{
    printf("%d %d %d\n", ptr_state->eightV, ptr_state->fiveV, ptr_state->threeV);
}

void set_state(state_t *ptr_state, int eightV, int fiveV, int threeV)
{
    ptr_state->eightV = eightV;
    ptr_state->fiveV = fiveV;
    ptr_state->threeV = threeV;
}

//a state is invalid if total volume exceeds 8, or less than 0, and then we check the volume of individual jugs
int is_invalid(const state_t* ptr_state)
{
    int totalV = ptr_state->threeV + ptr_state->fiveV + ptr_state->eightV;
    return (ptr_state->eightV < 0 || ptr_state->eightV > 8) ||
            (ptr_state->fiveV < 0 || ptr_state->fiveV > 5) ||
            (ptr_state->threeV < 0 || ptr_state->threeV > 3) ||
            (totalV < 0 || totalV > 8 );
}

//checks if a state is 4 4 0
int is_final_state(const state_t* ptr_state)
{
    return ptr_state->eightV == 4 && ptr_state->fiveV == 4 && ptr_state->threeV == 0;
}

int are_same(const state_t *lhs, const state_t *rhs)
{
	return lhs->eightV == rhs->eightV && lhs->fiveV == rhs->fiveV && lhs->threeV == rhs->threeV ;
}


//8->5 transition function
void move_85(const state_t *src, state_t *dst)
{
    //we can move till 5 is full or till 8 is empty
    if((5 - src->fiveV) < src->eightV)  //it'll overflow so don't move everything
    {
        dst->fiveV = 5;
        dst->eightV = src->eightV - (5 - src->fiveV);
    }
    else    //pour everything from 8
    {
        dst->fiveV = src->fiveV + src->eightV;
        dst->eightV = 0;
    }

    dst->threeV = src->threeV;
    dst->fn_index = 0;
}

//8->3 transition function
void move_83(const state_t *src, state_t *dst)
{
    //we can move till 3 is full or till 8 is empty
    if((3 - src->threeV) < src->eightV)  //it'll overflow so don't move everything
    {
        dst->threeV = 3;
        dst->eightV = src->eightV - (3 - src->threeV);
    }
    else    //pour everything from 8
    {
        dst->threeV = src->threeV + src->eightV;
        dst->eightV = 0;
    }

    dst->fiveV = src->fiveV;
    dst->fn_index = 0;
}

//5->8 transition function
void move_58(const state_t *src, state_t *dst)
{
    //we can move till 8 is full or till 5 is empty
    if((8 - src->eightV) < src->fiveV)  //it'll overflow so don't move everything
    {
        dst->eightV = 8;
        dst->fiveV = src->fiveV - (8 - src->eightV);
    }
    else    //pour everything from 5
    {
        dst->eightV =  src->eightV + src->fiveV;
        dst->fiveV = 0;
    }

    dst->threeV = src->threeV;
    dst->fn_index = 0;
}

//5->3 transition function
void move_53(const state_t *src, state_t *dst)
{
    //we can move till 3 is full or till 5 is empty
    if((3 - src->threeV) < src->fiveV)  //it'll overflow so don't move everything
    {
        dst->threeV = 3;
        dst->fiveV = src->fiveV - (3 - src->threeV);
    }
    else    //pour everything from 5
    {
        dst->threeV =  src->threeV + src->fiveV;
        dst->fiveV = 0;
    }

    dst->eightV = src->eightV;
    dst->fn_index = 0;
}

//3->8 transition function
void move_38(const state_t *src, state_t *dst)
{
    //we can move till 8 is full or till 3 is empty
    if((8 - src->eightV) < src->threeV)  //it'll overflow so don't move everything
    {
        dst->eightV = 8;
        dst->threeV = src->threeV - (8 - src->eightV);
    }
    else    //pour everything from 3
    {
        dst->eightV =  src->eightV + src->threeV;
        dst->threeV = 0;
    }

    dst->fiveV = src->fiveV;
    dst->fn_index = 0;
}

//3->5 transition function
void move_35(const state_t *src, state_t *dst)
{
    //we can move till 5 is full or till 3 is empty
    if((5 - src->fiveV) < src->threeV)  //it'll overflow so don't move everything
    {
        dst->fiveV = 5;
        dst->threeV = src->threeV - (5 - src->fiveV);
    }
    else    //pour everything from 3
    {
        dst->fiveV =  src->fiveV + src->threeV;
        dst->threeV = 0;
    }

    dst->eightV = src->eightV;
    dst->fn_index = 0;
}

void init_list(list_t *ptr_list)
{
	ptr_list->head = NULL;
	ptr_list->tail = NULL;
}

//adds a node to the tail of a list
void add_at_end(list_t *ptr_list, const state_t* ptr_state)

{
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	temp->st = *ptr_state;    //copies contents of ptr_state to temp->st
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

int remove_at_end(list_t *ptr_list)
{
	if(ptr_list->tail == NULL)
	{
		return 1;	//returns 1 if list is empty
	}
	else  
	{
		node_t* temp = ptr_list->tail;
		//printf("removing %d\n", temp->key);
		// disp_state(&temp->st);
		ptr_list->tail = ptr_list->tail->prev;	
		if(ptr_list->tail == NULL)
		{
			ptr_list->head = NULL;
			return 1;
		}
		else
		{
			ptr_list->tail->next = NULL;
		}
		free(temp);		
	}
	return 0;
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