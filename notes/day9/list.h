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
	node_t* head;
};
typedef struct list list_t;
void init_list(list_t *ptr_list);
void add_at_begin(list_t *ptr_list, int key);
void disp_list(const list_t * ptr_list);
void write_file(const list_t *ptr_list, FILE* fp);
void read_file(list_t *ptr_list, FILE *fp);
#endif

