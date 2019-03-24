#include <stdio.h>
#include <stdlib.h>
#include "codell.h"

void init_list(linkedlist *p)
{
    p->head = NULL;
}

void insert_beg(linkedlist *p, int key)
{
    node *temp = p->head;

    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = key;
    newNode->next = NULL;

    if(temp == NULL)
    {
        p->head = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
}

void disp_list(const linkedlist *p)
{
    node *temp = p->head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int is_empty(const linkedlist *p)
{
    return p->head == NULL;
}

void make_empty(linkedlist *p)
{
    //TODO: fix the way i free
    if(p->head != NULL)
    {
        free(p->head);
        p->head = NULL;
    }
}