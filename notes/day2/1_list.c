#include <stdio.h>
#include <stdlib.h>
#include "1_list.h"
#define ALLOC(x) (x*)malloc(sizeof(x))
#if 0
void init(list_t *ptr_list)
{
	ptr_list->head_ = 0;
}
void disp(const list_t *ptr_list)
{
	node_t_* pres = ptr_list->head_;
	while(pres)
	{
		printf("%d ", pres->key_);
		pres = pres->link_;
	}
	printf("\n");
}
node_t_* make_node_(int key)
{
	node_t_* temp = ALLOC(node_t_);
	temp->key_ = key;
	temp->link_ = 0;
	return temp;
}
void insert(list_t *ptr_list, int key)
{
	// make a node and populate it
	node_t_*temp = make_node_(key);
	// 1. empty list
	if(ptr_list->head_ == 0)
	{	
		ptr_list->head_ = temp;
		temp->link_ = 0;
	}
	else
	{
		node_t_ *prev = 0; node_t_ *pres = ptr_list->head_;
		while(pres != 0 && pres->key_ < temp->key_)
		{
			prev = pres;
			pres = pres->link_;
		}
		if(prev == 0) // beginning
		{
			ptr_list->head_ = temp;
			temp->link_ = pres;
		}
		else // middle or end
		{
			prev->link_ = temp;
			temp->link_ = pres;
		}
	}
}

#endif

// header node
//	empty list will have a node
node_t_* make_node_(int key)
{
	node_t_* temp = ALLOC(node_t_);
	temp->key_ = key;
	temp->link_ = 0;
	return temp;
}
void init(list_t *ptr_list)
{
	ptr_list->head_ = ALLOC(node_t_);
	// ingore the key field
	ptr_list->head_->link_ = 0;
}
void disp(const list_t *ptr_list)
{
	node_t_* pres = ptr_list->head_->link_;
	while(pres)
	{
		printf("%d ", pres->key_);
		pres = pres->link_;
	}
	printf("\n");
}

void insert(list_t *ptr_list, int key)
{
	// make a node and populate it
	node_t_*temp = make_node_(key);
	
	node_t_ *prev = ptr_list->head_; node_t_ *pres = ptr_list->head_->link_;
	while(pres != 0 && pres->key_ < temp->key_)
	{
			prev = pres;
			pres = pres->link_;
	}
	
	prev->link_ = temp;
	temp->link_ = pres;
	
	
}



