#include <stdio.h>
#include "list.h"

int main()
{
#if 0
	list_t l;
	init_list(&l);
	add_at_end(&l, 11);
	disp_list(&l);
	add_at_end(&l, 22);
	disp_list(&l);
	add_at_end(&l, 33);
	disp_list(&l);
	remove_at_end(&l);
	remove_at_end(&l);
	remove_at_end(&l);
#endif
#if 0
	list_t l;
	init_list(&l);
	state_t temp;
	set_state(&temp, 3, 3, 0); 
	add_at_end(&l, &temp);
	set_state(&temp, 2, 2, 0); 
	add_at_end(&l, &temp);
	set_state(&temp, 1, 1, 0); 
	add_at_end(&l, &temp);
	disp_list(&l);

	remove_at_end(&l);
	remove_at_end(&l);
	remove_at_end(&l);
#endif

// init start state
// init final state
// while not solution do
//	find the next transition(new state)
//	if the new state is safe and not repeated then
//		add to the soln
//		if new state is same as final state
//			solution is found
//  else
//		try the next transition
//		while no more transition
//			backtrack

	state_t start_state;
	set_state(&start_state, 3, 3, 0);
	state_t goal_state;
	set_state(&goal_state, 0, 0, 1);
	list_t l;
	init_list(&l);
	state_t temp;
	int soln = 0;
	add_at_end(&l, &start_state);
	int index;

	void (*move[])(const state_t *src, state_t *dst) = {
		move_cc,
		move_mm,
		move_cm,
		move_c,
		move_m
	};
	while(! soln)
	{
		index = l.tail->st.fn_index;
		move[index](&l.tail->st , &temp);
		if(is_safe(&temp) && ! is_repeated(&l, &temp))
		{
			printf("adding\n");
			add_at_end(&l, &temp);
			//disp_state(&temp);
			soln = are_same(&temp, &goal_state);
		}
		else
		{
			// list empty not checked
			while(++l.tail->st.fn_index == 5)
			{
				printf("back tracking\n");
				remove_at_end(&l);
			}
			
		}

	}
	disp_list(&l);
#if 0
	//while(! soln)
	{
		index = l.tail->st.fn_index;
		move[index](&l.tail->st , &temp);
		add_at_end(&l, &temp);
		//disp_list(&l);
		++l.tail->st.fn_index;
		index = l.tail->st.fn_index;
		move[index](&l.tail->st , &temp);
		add_at_end(&l, &temp);
		disp_list(&l);

		
	}
#endif
}


