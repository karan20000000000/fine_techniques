#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init_tree(tree_t *ptr_tree)
{
    ptr_tree->root = NULL;
}

void inorder(node_t *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d ", p->key);
        inorder(p->right);
    }
}

void display_inorder(const tree_t *ptr_tree)
{
    inorder(ptr_tree->root);
    printf("\n");
}
// Space separated keys. Last key followed by '\n'

void preorder(node_t *p)
{
    if (p != NULL)
    {
        printf("%d ", p->key);
        preorder(p->left);
        preorder(p->right);
    }
}

void display_preorder(const tree_t *ptr_tree)
{
    preorder(ptr_tree->root);
    printf("\n");
}
// Space separated keys. Last key followed by '\n'

void insert_key(tree_t *ptr_tree, int key)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->key = key;
    newNode->left = newNode->right = NULL;

    if (ptr_tree->root == NULL)
    {
        ptr_tree->root = newNode;
    }
    else
    {
        node_t *temp = ptr_tree->root;
        node_t *prev = NULL;

        while (temp != NULL)
        {
            prev = temp;
            if (key < temp->key) //predicate < comes into picture
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (key < prev->key)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
    }
}

void delete_key(tree_t *ptr_tree, int key)
{
    if (ptr_tree->root == NULL)
        return;

    node_t *temp = ptr_tree->root;
    node_t *prev = NULL;

    while (temp != NULL && temp->key != key)
    {
        prev = temp;
        if (key < temp->key) //predicate < comes into picture
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp != NULL)
    {
        if (prev != NULL)
        {
            if (temp->right == NULL && temp->left == NULL)      //if node to be deleted is leaf
            {
                if (temp == prev->left)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }
            }
            else if (temp->right == NULL || temp->left == NULL)     //if node to be deleted has only one child
            {
                node_t *toBePlaced = (temp->left == NULL) ? temp->right : temp->left;
                if (temp == prev->left)
                {
                    prev->left = toBePlaced;
                }
                else
                {
                    prev->right = toBePlaced;
                }
            }
            else        //if node to be deleted has two children
            {
                //find the inorder successor
                node_t *insuc = temp->right;
                node_t *insucPred = NULL;
                while (insuc->left != NULL)
                {
                    insucPred = insuc;
                    insuc = insuc->left;
                }

                if (insucPred != NULL)
                {
                    insucPred->left = insuc->right;
                    insuc->right = temp->right;
                }

                insuc->left = temp->left;

                if (temp == prev->left)
                {
                    prev->left = insuc;
                }
                else
                {
                    prev->right = insuc;
                }
            }
        }
        else    //root is to be deleted
        {
            if(temp->right == NULL && temp->left == NULL)
            {  ptr_tree->root = NULL; }
            else if(temp->right == NULL || temp->left == NULL)
            {
                ptr_tree->root = (temp->left == NULL) ? temp->right : temp->left;
            }
            else
            {
                node_t *insuc = temp->right;
                node_t *insucPred = NULL;
                while (insuc->left != NULL)
                {
                    insucPred = insuc;
                    insuc = insuc->left;
                }

                if (insucPred != NULL)
                {
                    insucPred->left = insuc->right;
                    insuc->right = temp->right;
                }

                insuc->left = temp->left;

                ptr_tree->root = insuc;
            }
            
        }
        free(temp);
    }
}