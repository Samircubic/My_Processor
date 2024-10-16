#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

#include "safety.h"

    //TODO func- verify check
void plant_bird (stack_t *stk) //TODO my_assert -Dassert
{
    STACK_ASSERT;

    stk->data[-1] = TORTURE_CKAMBER; //TODO сделай возможность легко менять типы через дефанйы

    stk->data[stk->capacity + 1] = TORTURE_CKAMBER;
}

//----------------------------------------------------------------------

void check_bird (stack_t *stk, const char *file, int line) //TODO static-func
{
    STACK_ASSERT;

    if (compare_double (stk->data[-1], TORTURE_CKAMBER) != EQUALS)
    {
        printf (red "Attack on the bird!" black "\n");
        printf (blue "%s" black ", line = " blue "%d" black "\n", file, line);
        printf ("The left bird is gone\n");

        assert (0);
    }

    if (compare_double (stk->data[stk->capacity + 1], TORTURE_CKAMBER) != EQUALS)
    {
        printf (red "Attack on the bird!" black "\n");
        printf ("The right bird is gone\n");

        assert (0);
    }
}

//----------------------------------------------------------------------

int stack_error (stack_t *stk, const char *file, int line)
{
    // assert(stk) //TODO MYASSERT() - macros
    if (stk == 0) //TODO macro-local MACRO_
    {
        printf (red "ERROR " black "from " blue "%s" black ": " blue "%d\n" black, file, line);
        printf ("stk == " red "0" black "\n"); //TODO stk->error = enum of error; printf() in dump

        assert (0);
    }

    if (stk->data == 0)
    {
        printf (red "ERROR " black "from " blue "%s" black ": " blue "%d\n" black, file, line);
        printf ("stk->data == " red "0" black "\n");

        assert (0);
    }

    if ((stk->size > stk->capacity && stk->capacity > 0 )|| stk->size < 0)
    {
        printf (red "ERROR " black "from " blue "%s" black ": " blue "%d\n" black, file, line);
        printf ("Incorrect value, size = " red "%d" black "\n", stk->size);

        assert (0);
    }

    if (stk->capacity < 0)
    {
        printf (red "ERROR " black "from " blue "%s" black ": " blue "%d\n" black, file, line);
        printf ("Incorrect value, capacity = " red "%d" black "\n", stk->capacity);

        assert (0);
    }
    return 0;
}

//----------------------------------------------------------------------

int dump (stack_t *stk, const char *file, int line)
{
    CHECK_BIRD;

    printf ("ctack_t [" blue "%p" black "]\n"

            "called from " green "%s" black ": " green "%d\n" black
            "\tname " green "%s " black "born at " green "%d" black ": "green"\n" black

            "\t{\n"

            "\t\tcapacity = " green "%d\n" black

            "\t\tsize = " green "%d\n" black //TODO 331
            "\t\tdata [" blue "%p" black "]\n"

            "\t\t{\n",

            stk, file, line, stk->creation_file, stk->creation_line, stk->capacity, stk->size, stk->data);

    for (int i = 0; i < stk->size; i++)
    {
        printf (green "\t\t\t*[%d] " black "= %lf\n", i, stk->data[i]);         ///< вывод заполненой части стека
    }

    for (int i = stk->size; i < stk->capacity; i++)
    {
        printf ("\t\t\t[%d] = %lf " red "(POISON)\n" black, i, stk->data[i]);   ///< вывод незаполненой чатси стека (ядовитой)
    }

    printf ("\t\t}\n"

            "\t}\n");

    CHECK_BIRD;
    return 0;
}

//----------------------------------------------------------------------
//
// void calculation_hash (stack_t *stk)
// {
//
//     int hash = 0;
//     for (int i = 0; i < stk->capacity; i++)
//     {
//         hash += stk->data[i] % 100 % 53 % 17
//     }
// }
//
// //----------------------------------------------------------------------
//
// void check_hash (stack_t *stk)
// {
//
// }
//
// //----------------------------------------------------------------------
