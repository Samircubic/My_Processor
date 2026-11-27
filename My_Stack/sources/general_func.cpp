#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "general_func.h"

edu_stack_t* get_point_stack (int line)
{
    edu_stack_t *stk = (edu_stack_t*) calloc (1, sizeof (edu_stack_t));
    assert (stk);

    stk->creation_line = line;

    return stk;
}

//----------------------------------------------------------------------

enum comparison compare_double (double x, double z)
{
    if (fabs (x - z) < EPSILONT)
    {
        return EQUALS;
    }

    if ((x - z) > EPSILONT)
    {
        return MORE;
    }

    else
    {
        return LESS;
    }
}

//----------------------------------------------------------------------
