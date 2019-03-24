#include <stdio.h>
#include <stdlib.h>
#include "codenode.h"

void insert_beg(node **p, int key)
{
    node *temp = *p;

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = key;
    newNode->next = NULL;

    if (temp == NULL)
    {
        *p = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insert_head(node **p, int key)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = key;
    newNode->next = NULL;

    if(*p != NULL)
    {
        newNode->next = *p;
    }
    *p = newNode;
}

void disp_list(const node *p)
{
    node *temp = p;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    // printf("\n");
}