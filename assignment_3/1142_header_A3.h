#ifndef header
#define header

//state part
struct state
{
	int eightV; // volume of milk in 8 litre jug
	int fiveV; // volume of milk in 5 litre jug
	int threeV; // volume of milk in 3 litre jug

	// implementation field
	int fn_index;
};
typedef struct state state_t;
void init_state(state_t *ptr_state);
void disp_state(const state_t *ptr_state);
void set_state(state_t *ptr_state, int eightV, int fiveV, int threeV);

void move_85(const state_t *src, state_t *dst);
void move_83(const state_t *src, state_t *dst);
void move_58(const state_t *src, state_t *dst);
void move_53(const state_t *src, state_t *dst);
void move_38(const state_t *src, state_t *dst);
void move_35(const state_t *src, state_t *dst);

void set_state(state_t *ptr_state, int eightV, int fiveV, int threeV);
int is_invalid(const state_t* ptr_state);
int are_same(const state_t *lhs, const state_t *rhs);
int is_final_state(const state_t* ptr_state);


//list part
struct node
{
	//int key;
	state_t st;
	struct node *next;
	struct node *prev;
};
typedef struct node node_t;
struct list
{
	node_t* head;
	node_t* tail;
};
typedef struct list list_t;
void init_list(list_t *ptr_list);
//void add_at_end(list_t *ptr_list, int key);
void add_at_end(list_t *ptr_list, const state_t* ptr_state);

int remove_at_end(list_t *ptr_list);
void disp_list(const list_t *ptr_list);

int is_repeated(const list_t* ptr_list, const state_t* ptr_state);

#endif