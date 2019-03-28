#pragma once

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