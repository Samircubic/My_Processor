#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include <cstring>
#include "my_stack.h"

int main ()
{
    stack_t *stk = get_point_stack (__LINE__);
    assert (stk);

    stk->creation_file = "stk";

    ctor_stack (stk);

    while (1)
    {
        char cmd[50] = "";
        scanf ("%s", cmd);



        if (strcmp (cmd, "stop") == 0)
        {
            printf ("Программа завершена\n");

            break;
        }
        else if (strcmp (cmd, "push") == 0)
        {
            double org = 0;
            scanf ("%lg", &org);

            push (stk, org);
        }
        else if (strcmp (cmd, "out") == 0)
        {
            if (stk->size >= 1)
            {
                double org = 0;
                pop (stk, &org);

                printf ("%g\n", org);
            }
            else
            {
                printf ("На данный мометн у меня нет чисел для вывода\n");
            }
        }
        else if (strcmp (cmd, "add") == 0)
        {
            if (stk->size < 2)
            {
                printf ("На данный момент чисел для сложения не достаточно\n");
            }
            else
            {
                double number_one = 0;
                double number_two = 0;
                pop (stk, &number_one);
                pop (stk, &number_two);

                push (stk, number_one + number_two);
            }
        }
        else if (strcmp (cmd, "sub") == 0)
        {
            if (stk->size < 2)
            {
                printf ("На данный момент чисел для вычитания не достаточно\n");
            }
            else
            {
                double number_one = 0;
                double number_two = 0;
                pop (stk, &number_one);
                pop (stk, &number_two);

                push (stk, number_two - number_one);
            }
        }
        else if (strcmp (cmd, "div") == 0)
        {
            if (stk->size < 2)
            {
                printf ("На данный момент чисел для деления не достаточно\n");
            }
            else
            {
                double number_one = 0;
                double number_two = 0;
                pop (stk, &number_one);
                pop (stk, &number_two);

                push (stk, number_two / number_one);
            }
        }
        else if (strcmp (cmd, "htl") == 0)
        {
            DUMP
        }
        else if (strcmp (cmd, "sqrt") == 0)
        {
            if (stk->size < 1)
            {
                printf ("На данный момент чисел для корня не достаточно\n");
            }
            else
            {
                double number = 0;
                pop (stk, &number);

                push (stk, pow (number, 0.5));
            }
        }
        else if (strcmp (cmd, "sin") == 0)
        {
            if (stk->size < 1)
            {
                printf ("На данный момент чисел для синуса не достаточно\n");
            }
            else
            {
                double number = 0;
                pop (stk, &number);

                push (stk, sin (number));
            }
        }
        else if (strcmp (cmd, "cos") == 0)
        {
            if (stk->size < 1)
            {
                printf ("На данный момент чисел для косинуса не достаточно\n");
            }
            else
            {
                double number = 0;
                pop (stk, &number);

                push (stk, cos (number));
            }
        }
        else
        {
            printf ("Неккоректный ввод\n");
        }
    }

    dtor_stack (stk);
    return 0;
}
