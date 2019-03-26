#include <stdio.h>
#include "state.h"

void init_state(state_t *ptr_state)
{
    ptr_state->eightV = 8;
    ptr_state->fiveV = 0;
    ptr_state->threeV = 0;

    ptr_state->fn_index = 0;
}


void disp_state(const state_t *ptr_state)
{
    printf("EightJug: %d, FiveJug: %d, ThreeJug: %d\n", ptr_state->eightV, ptr_state->fiveV, ptr_state->threeV);
}

void set_state(state_t *ptr_state, int eightV, int fiveV, int threeV)
{
    ptr_state->eightV = eightV;
    ptr_state->fiveV = fiveV;
    ptr_state->threeV = threeV;
}

int is_invalid(const state_t* ptr_state)
{
    int totalV = ptr_state->threeV + ptr_state->fiveV + ptr_state->eightV;
    return (ptr_state->eightV < 0 && ptr_state->eightV > 8) ||
            (ptr_state->fiveV < 0 && ptr_state->fiveV > 5) ||
            (ptr_state->threeV < 0 && ptr_state->threeV > 3) ||
            (totalV < 0 || totalV > 8 );
}
int is_final_state(const state_t* ptr_state)
{
    return ptr_state->eightV == 4 || ptr_state->fiveV == 4;
}

int are_same(const state_t *lhs, const state_t *rhs)
{
	return lhs->eightV == rhs->eightV && lhs->fiveV == rhs->fiveV && lhs->threeV == rhs->threeV ;
}

void move_85(const state_t *src, state_t *dst)
{
    //we can move till 5 is full or till 8 is empty
    if((5 - src->fiveV) < src->eightV)  //it'll overflow so don't move everything
    {
        dst->fiveV = 5;
        dst->eightV = src->eightV - (5 - src->fiveV);
    }
    else    //pour everything from 8
    {
        dst->fiveV = src->fiveV + src->eightV;
        dst->eightV = 0;
    }

    dst->threeV = src->threeV;
    dst->fn_index = 0;
}

void move_83(const state_t *src, state_t *dst)
{
    //we can move till 3 is full or till 8 is empty
    if((3 - src->threeV) < src->eightV)  //it'll overflow so don't move everything
    {
        dst->threeV = 3;
        dst->eightV = src->eightV - (3 - src->threeV);
    }
    else    //pour everything from 8
    {
        dst->threeV = src->threeV + src->eightV;
        dst->eightV = 0;
    }

    dst->fiveV = src->fiveV;
    dst->fn_index = 0;
}

void move_58(const state_t *src, state_t *dst)
{
    //we can move till 8 is full or till 5 is empty
    if((8 - src->eightV) < src->fiveV)  //it'll overflow so don't move everything
    {
        dst->eightV = 8;
        dst->fiveV = src->fiveV - (8 - src->eightV);
    }
    else    //pour everything from 5
    {
        dst->eightV =  src->eightV + src->fiveV;
        dst->fiveV = 0;
    }

    dst->threeV = src->threeV;
    dst->fn_index = 0;
}

void move_53(const state_t *src, state_t *dst)
{
    //we can move till 3 is full or till 5 is empty
    if((3 - src->threeV) < src->fiveV)  //it'll overflow so don't move everything
    {
        dst->threeV = 3;
        dst->fiveV = src->fiveV - (3 - src->threeV);
    }
    else    //pour everything from 5
    {
        dst->threeV =  src->threeV + src->fiveV;
        dst->fiveV = 0;
    }

    dst->eightV = src->eightV;
    dst->fn_index = 0;
}

void move_38(const state_t *src, state_t *dst)
{
    //we can move till 8 is full or till 3 is empty
    if((8 - src->eightV) < src->threeV)  //it'll overflow so don't move everything
    {
        dst->eightV = 8;
        dst->threeV = src->threeV - (8 - src->eightV);
    }
    else    //pour everything from 3
    {
        dst->eightV =  src->eightV + src->threeV;
        dst->threeV = 0;
    }

    dst->fiveV = src->fiveV;
    dst->fn_index = 0;
}

void move_35(const state_t *src, state_t *dst)
{
    //we can move till 5 is full or till 3 is empty
    if((5 - src->fiveV) < src->threeV)  //it'll overflow so don't move everything
    {
        dst->fiveV = 8;
        dst->threeV = src->threeV - (5 - src->fiveV);
    }
    else    //pour everything from 3
    {
        dst->fiveV =  src->fiveV + src->threeV;
        dst->threeV = 0;
    }

    dst->eightV = src->eightV;
    dst->fn_index = 0;
}