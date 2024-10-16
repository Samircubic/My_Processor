#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include <cstring>

const int FILE_NAME_INPUT = 1;
const int FILE_NAME_OUTPUT = 2;

int function_definition (char *cmd);

int main (int argc, const char *argv[])
{
    FILE *pointer_file_input = fopen (argv[FILE_NAME_INPUT], "rb");
    assert (pointer_file_input);
    printf ("%s\n", argv[FILE_NAME_INPUT]);

    FILE *pointer_file_output = fopen (argv[FILE_NAME_OUTPUT], "wr");
    assert (pointer_file_output);

    int number_function = 1;
    while (number_function != 0)
    {
        char cmd[50] = "";

        fscanf (pointer_file_input, "%s", cmd);
        printf ("%s\n", cmd);

        number_function = function_definition (cmd);

        int number = 0;
        switch (number_function)
        {
            case 0:
              fprintf (pointer_file_output, "%d\n", number_function);

              break;
            case 1:
              fprintf (pointer_file_output, "%d\n", number_function);

              fscanf (pointer_file_input, "%d\n", &number);
              fprintf (pointer_file_output, "%d\n", number);

              break;
            case 2:
              fprintf (pointer_file_output, "%d\n", number_function);

              break;
            case 3:
              fprintf (pointer_file_output, "%d\n", number_function);

              break;
            default:
              fprintf (pointer_file_output, "%d\n", number_function);
              fprintf (pointer_file_output, "произошла ошибка\n");
              
              break;
        }
    }

    printf ("программа переведена на машинный код\n");

    fclose (pointer_file_input);
    fclose (pointer_file_output);

    return 0;
}

//---------------------------------------------------------------------------

int function_definition (char cmd[50])
{
    printf ("%s\n", cmd);
    if (strcmp (cmd, "htl") == 0)
    {
        return 0;
    }
    else if (strcmp (cmd, "push") == 0)
    {
        return 1;
    }
    else if (strcmp (cmd, "pop") == 0)
    {
        return 2;
    }
    else if (strcmp (cmd, "add") == 0)
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
