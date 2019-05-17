#if 0
#ifndef LIST_H
#define LIST_H
struct node_
{
	int key_;
	struct node_ *link_;
};
typedef struct node_ node_t_;
struct list
{
	node_t_ *head_;
};
typedef struct list list_t;
void init(list_t *ptr_list);
void disp(const list_t *ptr_list);
void insert(list_t *ptr_list, int key);
#endif
#endif

#ifndef LIST_H
#define LIST_H
struct node_
{
	int key_;
	struct node_ *link_;
};
typedef struct node_ node_t_;
struct list
{
	node_t_ *head_;
};
typedef struct list list_t;
void init(list_t *ptr_list);
void disp(const list_t *ptr_list);
void insert(list_t *ptr_list, int key);
#endif



