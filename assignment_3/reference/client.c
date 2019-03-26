#include <stdio.h>
#include "state.h"

int main()
{
	state_t s;
	state_t r;
	init_state(&s);
	disp_state(&s);
	//move_cc(&s, &r);
	//disp_state(&r);
	// create an array of pointers to functions
	void (*move[])(const state_t *src, state_t *dst) = {
		move_cc,
		move_mm,
		move_cm,
		move_c,
		move_m
	};
	for(int i = 0; i < 5; ++i)
	{
		move[i](&s, &r);
		disp_state(&r);
	}

	set_state(&s, 0, 0, 1);
	for(int i = 0; i < 5; ++i)
	{
		move[i](&s, &r);
		disp_state(&r);
	}




}
