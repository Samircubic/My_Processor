#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

#include "c_d_tor.h"

void ctor_stack (stack_t *stk)
{
    assert (stk);
 //TODO rename extra, why is 3 //TODO verify()
    stk->data = ((STACK_ELEM*) calloc (INITIAL_LENGHT + EXTRA_MEMORY_CANARIES, sizeof (STACK_ELEM))) + OFFSET_BIRD; //TODO magic-const
    assert (stk->data);

    stk->size = 0;
    stk->capacity = INITIAL_LENGHT;

    plant_bird (stk); //заполнение птичек func static

    for (int i = stk->size; i < stk->capacity; i++) //TODO Func memcpy
    {
        stk->data[i] = NAN;
    }

    // hash_func();
}

//----------------------------------------------------------------------

int dtor_stack (stack_t *stk)
{
    CHECK_BIRD; 

    for (int i = 0; i < stk->capacity; i++) //TODO func memcpy
    {
        stk->data[i] = NAN;
    }

    stk->size = POISON;
    stk->capacity = POISON;

    free (stk->data - OFFSET_BIRD);
    stk->data = 0;

    free (stk);
    stk = NULL; //TODO NULL

    return 0;
}

//----------------------------------------------------------------------
