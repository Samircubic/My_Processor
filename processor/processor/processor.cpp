#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <cstring>
#include "my_stack.h"

const int FILE_NAME_INPUT = 1;

int main (int argc, const char *argv[])
{
    if (argc != 2)
    {
        fprintf (stderr, "Usage: %s PROGRAM\n", argv[0]);
        return 1;
    }
    FILE *pointer_file_input = fopen (argv[FILE_NAME_INPUT], "rb");
    if (!pointer_file_input) { perror (argv[FILE_NAME_INPUT]); return 1; }

    edu_stack_t *stk = get_point_stack (__LINE__);
    stk->creation_file = "stk";
    ctor_stack (stk);

    int opcode = -1;
    bool finished = false;
    while (fscanf (pointer_file_input, "%d", &opcode) == 1)
    {
        if (opcode == 0) { finished = true; break; }
        if (opcode == 1)
        {
            int value = 0;
            if (fscanf (pointer_file_input, "%d", &value) != 1) break;
            push (stk, value);
        }
        else if (opcode == 2 && stk->size >= 1)
        {
            double value = 0;
            pop (stk, &value);
            printf ("%g\n", value);
        }
        else if (opcode == 3 && stk->size >= 2)
        {
            double right = 0, left = 0;
            pop (stk, &right);
            pop (stk, &left);
            push (stk, left + right);
        }
        else break;
    }
    if (!finished) fprintf (stderr, "Invalid instruction, stack underflow or missing halt\n");
    fclose (pointer_file_input);
    dtor_stack (stk);
    return finished ? 0 : 1;
}
