#include <stdio.h>
#include "state.h"
#include "list.h"

int main()
{
    freopen("output.txt", "w", stdout);
    state_t start_state;
    set_state(&start_state, 8, 0, 0);

    void (*move[])(const state_t *src, state_t *dst) = {
		move_85,
		move_83,
		move_58,
		move_53,
		move_38,
        move_35
	};


    list_t l;
    init_list(&l);
    state_t temp;
    add_at_end(&l, &start_state);

    int soln = 0;

    int index = 0;

    int executing = 1;
    int numSolutions = 0;

    while(executing)
	{
		index = l.tail->st.fn_index;
		move[index](&l.tail->st , &temp);
		if(!is_invalid(&temp) && ! is_repeated(&l, &temp))
		{
			// printf("adding\n");
			add_at_end(&l, &temp);
			soln = is_final_state(&temp);

            if(soln)
            {  
                numSolutions++;
                // printf("Solution: %d\n", numSolutions);
                disp_list(&l);
                printf("\n");
                if(index < 6)
                { l.tail->st.fn_index++; }
                // else
                // {
                //     printf("HERE\n");
                //     remove_at_end(&l);
                //     l.tail->st.fn_index++;
                // }
                soln = 0;
            }
		}
		else
		{
			// list empty checked
			while(l.tail != NULL && ++l.tail->st.fn_index == 6)
			{
				// printf("back tracking\n");
				int empty = remove_at_end(&l);
                if(empty)
                {
                    executing = 0;
                }
			}
			
		}

	}

    // disp_list(&l);

    printf("%d\n", numSolutions);


}