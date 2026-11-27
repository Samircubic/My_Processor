#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <cstring>

const int FILE_NAME_INPUT = 1;
const int FILE_NAME_OUTPUT = 2;

int function_definition (char *cmd);

int main (int argc, const char *argv[])
{
    if (argc != 3)
    {
        fprintf (stderr, "Usage: %s INPUT OUTPUT\n", argv[0]);
        return 1;
    }
    FILE *pointer_file_input = fopen (argv[FILE_NAME_INPUT], "rb");
    if (!pointer_file_input) { perror (argv[FILE_NAME_INPUT]); return 1; }

    FILE *pointer_file_output = fopen (argv[FILE_NAME_OUTPUT], "w");
    if (!pointer_file_output)
    {
        perror (argv[FILE_NAME_OUTPUT]);
        fclose (pointer_file_input);
        return 1;
    }

    int number_function = 1;
    while (number_function != 0)
    {
        char cmd[50] = "";

        if (fscanf (pointer_file_input, "%49s", cmd) != 1) break;

        number_function = function_definition (cmd);

        int number = 0;
        switch (number_function)
        {
            case 0:
              fprintf (pointer_file_output, "%d\n", number_function);

              break;
            case 1:
              fprintf (pointer_file_output, "%d\n", number_function);

              if (fscanf (pointer_file_input, "%d", &number) != 1) { number_function = -1; break; }
              fprintf (pointer_file_output, "%d\n", number);

              break;
            case 2:
              fprintf (pointer_file_output, "%d\n", number_function);

              break;
            case 3:
              fprintf (pointer_file_output, "%d\n", number_function);

              break;
            default:
              number_function = -1;
              break;
        }
        if (number_function < 0) break;
    }
    if (number_function != 0)
        fprintf (stderr, "Invalid instruction or missing htl\n");

    fclose (pointer_file_input);
    fclose (pointer_file_output);

    return number_function == 0 ? 0 : 1;
}

//---------------------------------------------------------------------------

int function_definition (char cmd[50])
{
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
