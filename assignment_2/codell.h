typedef struct node
{
    int data;
    struct node * next;
} node;

typedef struct linkedlist
{
    node * head;
} linkedlist;

void init_list(linkedlist *p);
void insert_beg(linkedlist *p, int key);
void disp_list(const linkedlist *p);
int is_empty(const linkedlist *p);
void make_empty(linkedlist *p);