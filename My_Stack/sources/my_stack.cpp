#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include "my_stack.h"

int main ()
{
    stack_t *stk = get_point_stack (__LINE__); //static - func and ... функция статик транслирует код функции только один раз в один файл, вполне можно использовать для защиты программы от взлома через некоторые функции
    assert (stk);

    stk->creation_file = "stk"; //TODO __FILE__, read about # aqnd ## in define, __FUNC__

    ctor_stack (stk);

    DUMP;

    for (int i = 0; i < 100; i++) 
    {
        push (stk, 1);
    }

    // steck_error (stk);

    DUMP;

    for (int i = 0; i < 200; i++)
    {
        push (stk, 2);
    }

    DUMP;

    for (int i = 0; i < 200; i++)
    {
        double number = 0;
        pop (stk, &number);
        printf ("%lf\n", number);
    }

    DUMP;

    dtor_stack (stk);
    return 0;
}

//----------------------------------------------------------------------

// 3) макрос error
// 4) макрос ctor



// вопрос как реализовать кукумбер в масиве с войд звездочками
// то есть, нам нужно одну ячейку заполнить птичкой, а на сколько нам нужно сдвинуться мы не знаем, по скольку не знаем какие данные у нас хранятся в массиве.


//вопрос, я же правильно понял что взлом происходит только через мейн файл?
