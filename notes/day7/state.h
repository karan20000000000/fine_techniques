#ifndef STATE_H
#define STATE_H
struct state
{
	int can; // # of C on the left bank
	int mis; // # of M on the left bank
	int pos; // boat pos; 0 : left 1 : right
};
typedef struct state state_t;
void init_state(state_t *ptr_state);
void disp_state(const state_t *ptr_state);
void set_state(state_t *ptr_state, int can, int mis, int pos);

void move_cc(const state_t *src, state_t *dst);
void move_mm(const state_t *src, state_t *dst);
void move_cm(const state_t *src, state_t *dst);
void move_c(const state_t *src, state_t *dst);
void move_m(const state_t *src, state_t *dst);


#endif

