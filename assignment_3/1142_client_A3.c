#include <stdio.h>
#include "1142_header_A3.h"

int main()
{
    freopen("1142_A3_op.txt", "w", stdout);     //this redirects the stdout to the file 1142_A3_op.txt
    state_t start_state;
    set_state(&start_state, 8, 0, 0);


    //the array of pointers to functions
    void (*move[])(const state_t *src, state_t *dst) = {
		move_85,
		move_83,
		move_58,
		move_53,
		move_38,
        move_35
	};


    //solution list
    list_t l;
    init_list(&l);
    state_t temp;

    //adding the initial (start) state
    add_at_end(&l, &start_state);

    //solution indicates whether we've found a solution yet, index is a variable to store function index value
    int soln = 0;
    int index = 0;

    //executing var allows us to check whether we've tried all possibilites, it stops the while loop if we've tried everything
    int executing = 1;
    int numSolutions = 0;

    while(executing)
	{
		index = l.tail->st.fn_index;                            //get the index
		move[index](&l.tail->st , &temp);                       //make a transition, and store in temp
		if(!is_invalid(&temp) && ! is_repeated(&l, &temp))
		{
			add_at_end(&l, &temp);                              //add to list if not invalid and repeated
			soln = is_final_state(&temp);

            //if we've found a solution, then increase the number of solutions and increment the index of temp variable to try other possibilites (useful if there are more than one goal states (not useful in this case))
            if(soln)
            {  
                numSolutions++;
                disp_list(&l);
                printf("\n");
                if(index < 6)
                { l.tail->st.fn_index++; }
                soln = 0;
            }
		}
		else        //backtracking part
		{
			while(l.tail != NULL && ++l.tail->st.fn_index == 6) //increment the function index of last node's state to try other possibilites
			{
				int empty = remove_at_end(&l);  //popping if last node's state has already reached tried function/transition in the function array

                //if the solution list has become empty, we've backtracked back to start state, and tried all possibilites, so no more transitions left.
                if(empty)
                {
                    executing = 0;
                }
			}
			
		}

	}


    printf("%d", numSolutions);


}