#ifndef LIST_H
#define LIST_H
struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;
struct list
{
	node_t *head;
};
typedef struct list list_t;
void init_list(list_t *);
void disp_list(const list_t *);
void insert_key(list_t *, int);
void delete_key(list_t *, int);
#endif
