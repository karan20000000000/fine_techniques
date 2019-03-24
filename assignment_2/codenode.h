typedef struct node
{
    int data;
    struct node * next;
} node;

void insert_head(node **p, int key);
void insert_beg(node **p, int key);
void disp_list(const node *p);
