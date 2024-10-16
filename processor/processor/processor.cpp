#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include <cstring>
#include "my_stack.h"

const int FILE_NAME_INPUT = 1;

int function_definition (char *cmd);

int main (int argc, const char *argv[])
{
    stack_t *stk = get_point_stack (__LINE__);
    assert (stk);

    stk->creation_file = "stk";

    ctor_stack (stk);

    FILE *pointer_file_input = fopen (argv[FILE_NAME_INPUT], "rb");
    assert (pointer_file_input);
    printf ("%s\n", argv[FILE_NAME_INPUT]);

    int number_function = 1;
    int number = 0;
    while (number_function != 0)
    {
        fscanf (pointer_file_input, "%d", &number_function);
        printf ("%d\n", number_function);

        switch (number_function)
        {
            case 0:
              printf ("Выполнение программы завершено.\n");

              break;
            case 1:
              fscanf (pointer_file_input, "%d\n", &number);
              push (stk, number);

              break;
            case 2:
              fprintf (pointer_file_output, "%d\n", number_function);

              break;
//             case 3:
//               fprintf (pointer_file_output, "%d\n", number_function);
//
//               break;
            default:
              printf ("произошла ошибка\n");

              break;
        }
    }

    fclose (pointer_file_input);
    dtor_stack (stk);
    return 0;
}
