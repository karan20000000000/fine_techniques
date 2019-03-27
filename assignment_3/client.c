#include <stdio.h>
// #include "state.h"
#include "list.h"

int main()
{
    state_t start_state;
    set_state(&start_state, 8, 0, 0);

    void (*move[])(const state_t *src, state_t *dst) = {
        fill_85,
        fill_83,
        fill_53,
        empty_85,
        empty_83,
        empty_58,
        empty_53,
        empty_38,
        empty_35};

    int moveSize = 9;

    list_t l;
    init_list(&l);
    state_t temp, goal_state;
    add_at_end(&l, &start_state);

    set_state(&goal_state, 4, 4, 0);

    int soln = 0;

    int index = 0;

    int executing = 1;
    int numSolutions = 0;

    while (executing)
    {
        index = l.tail->st.fn_index;
        move[index](&l.tail->st, &temp);
        if (!is_invalid(&temp) && !is_repeated(&l, &temp))
        {
            // printf("adding\n");
            add_at_end(&l, &temp);
            soln = are_same(&temp, &goal_state);

            if (soln)
            {
                numSolutions++;
                printf("Solution: %d\n", numSolutions);
                disp_list(&l);
                printf("\n");
                if (index < moveSize)
                {
                    l.tail->st.fn_index++;
                }
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
            while (l.tail != NULL && ++l.tail->st.fn_index == moveSize)
            {
                // printf("back tracking\n");
                int empty = remove_at_end(&l);
                if (empty)
                {
                    executing = 0;
                }
            }
        }
    }

    // disp_list(&l);
}