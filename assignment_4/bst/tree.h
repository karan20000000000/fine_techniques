#pragma once

struct node
{
	int key;
	struct node *left;
    struct node *right;
};
typedef struct node node_t;

struct tree
{
	struct node *root;
};
typedef struct tree tree_t;

void init_tree(tree_t*);

void display_inorder(const tree_t *ptr_tree);
	// Space separated keys. Last key followed by '\n'

void display_preorder(const tree_t *ptr_tree);
	// Space separated keys. Last key followed by '\n'

void insert_key(tree_t *ptr_tree, int key);

void delete_key(tree_t *ptr_tree, int key);