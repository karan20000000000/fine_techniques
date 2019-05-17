#include <stdio.h>
#include "state.h"

void init_state(state_t *ptr_state)
{
	ptr_state->can = 3;
	ptr_state->mis = 3;
	ptr_state->pos = 0;
}
void disp_state(const state_t *ptr_state)
{
	printf("can : %d mis : %d pos : %d\n", ptr_state->can, ptr_state->mis, ptr_state->pos);
}

void move_cc(const state_t *src, state_t *dst)
{
	if(src->pos == 0)
	// left to right
	{
		dst->can = src->can - 2;
	}
	else
	// right to left
	{
		dst->can = src->can + 2;
	}
	dst->mis = src->mis;
	dst->pos = ! src->pos;
}
void move_mm(const state_t *src, state_t *dst)
{
	if(src->pos == 0)
	// left to right
	{
		dst->mis = src->mis - 2;
	}
	else
	// right to left
	{
		dst->mis = src->mis + 2;
	}
	dst->can = src->can;
	dst->pos = ! src->pos;
}
void move_cm(const state_t *src, state_t *dst)
{
	if(src->pos == 0)
	// left to right
	{
		dst->can = src->can - 1;
		dst->mis = src->mis - 1;
	}
	else
	// right to left
	{
		dst->can = src->can + 1;
		dst->mis = src->mis + 1;
	}
	dst->pos = ! src->pos;
}
void move_c(const state_t *src, state_t *dst)
{
	if(src->pos == 0)
	// left to right
	{
		dst->can = src->can - 1;
	}
	else
	// right to left
	{
		dst->can = src->can + 1;
	}
	dst->mis = src->mis;
	dst->pos = ! src->pos;
}
void move_m(const state_t *src, state_t *dst)
{
	if(src->pos == 0)
	// left to right
	{
		dst->mis = src->mis - 1;
	}
	else
	// right to left
	{
		dst->mis = src->mis + 1;
	}
	dst->can = src->can;
	dst->pos = ! src->pos;
}

void set_state(state_t *ptr_state, int can, int mis, int pos)
{
	ptr_state->can = can;
	ptr_state->mis = mis;
	ptr_state->pos = pos;
}



