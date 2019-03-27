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
    ptr_state->fn_index = 0;
}

int is_invalid(const state_t *ptr_state)
{
    int totalV = ptr_state->threeV + ptr_state->fiveV + ptr_state->eightV;
    return (ptr_state->eightV < 0 || ptr_state->eightV > 8) ||
           (ptr_state->fiveV < 0 || ptr_state->fiveV > 5) ||
           (ptr_state->threeV < 0 || ptr_state->threeV > 3) ||
           (totalV < 0 || totalV > 8);
}
int is_final_state(const state_t *ptr_state)
{
    return ptr_state->eightV == 4 || ptr_state->fiveV == 4;
}

int are_same(const state_t *lhs, const state_t *rhs)
{
    return lhs->eightV == rhs->eightV && lhs->fiveV == rhs->fiveV && lhs->threeV == rhs->threeV;
}

void fill_85(const state_t *src, state_t *dst)
{
    dst->fiveV = 5;
    dst->eightV = src->eightV - (5 - src->fiveV); //could become negative
    dst->threeV = src->threeV;
}

void fill_83(const state_t *src, state_t *dst)
{
    dst->threeV = 3;
    dst->eightV = src->eightV - (3 - src->threeV);
    dst->fiveV = src->fiveV;
}

void fill_53(const state_t *src, state_t *dst)
{
    dst->threeV = 3;
    dst->fiveV = src->fiveV - (3 - src->threeV);
    dst->eightV = src->eightV;
}

void empty_85(const state_t *src, state_t *dst)
{
    dst->fiveV = src->fiveV + src->eightV;
    dst->eightV = 0;
    dst->threeV = src->threeV;
}

void empty_83(const state_t *src, state_t *dst)
{
    dst->threeV = src->threeV + src->eightV;
    dst->eightV = 0;
    dst->fiveV = src->fiveV;
}

void empty_58(const state_t *src, state_t *dst)
{
    dst->eightV = src->eightV + src->fiveV;
    dst->fiveV = 0;
    dst->threeV = src->threeV;
}

void empty_53(const state_t *src, state_t *dst)
{
    dst->threeV = src->threeV + src->fiveV;
    dst->fiveV = 0;
    dst->eightV = src->eightV;
}

void empty_38(const state_t *src, state_t *dst)
{
    dst->eightV = src->eightV + src->threeV;
    dst->threeV = 0;
    dst->fiveV = src->fiveV;
}

void empty_35(const state_t *src, state_t *dst)
{
    dst->fiveV = src->fiveV + src->threeV;
    dst->threeV = 0;
    dst->eightV = src->eightV;
}