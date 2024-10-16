#ifndef MY_STACK_H
#define MY_STACK_H

#include "data_type_stack.h"

//----------------------------------------------------------------------

#define red     "\033[31m"                          ///< изменения цвета вывода на красный
#define blue    "\x1b[34m"                          ///< изменения цвета вывода на синий
#define white   "\x1b[37m"                          ///< изменения цвета вывода на белый
#define green   "\x1b[32m"                          ///< изменения цвета вывода на зеленый
#define black   "\x1b[30m"                          ///< изменения цвета вывода на черный

#define STACK_ASSERT    stack_error (stk, __FILE__, __LINE__);  ///< легкая подстановка функции проверки данных стека
#define CHECK_BIRD      check_bird  (stk, __FILE__, __LINE__);  ///< легкая подстановка функция проверки целостности данных

#ifndef _DEBUG
#define DUMP ;

#else
#define DUMP dump        (stk, __FILE__, __LINE__);            ///< подключение вывода данных стека в необходимых местах

#endif //_DEBUG

//----------------------------------------------------------------------

enum comparison                                     ///< необходим для возврата итогов функции сранения двух даболовских чисел
{
    MORE,
    EQUALS,
    LESS
};

//----------------------------------------------------------------------
//----------------------------------------------------------------------

typedef struct stack
{
    STACK_ELEM*     data;
    int             size;
    int             capacity;
    char            *creation_file;
    int             creation_line;
    int             hash_data;
    int             hash_struct;
} stack_t;

//----------------------------------------------------------------------

/*!
на вход принимаются два числа double для сравнения, функция возвращает итог сравнения\n
\param[in] x первый сравниваемый параметр\n
\param[in] z второй сравниваемый параметр\n
\return возврат результата сравнения
*/
enum comparison     compare_double      (double x, double z);

stack_t*            get_point_stack     (int line);
int                 dump                (stack_t *stk, const char *file, int line);
int                 push                (stack_t *stk, double elem);
int                 dtor_stack          (stack_t *stk);
int                 pop                 (stack_t *stk, double *elem);
int                 stack_error         (stack_t *stk, const char *file, int line);
void                ctor_stack          (stack_t *stk);
void                plant_bird          (stack_t *stk);
void                check_bird          (stack_t *stk, const char *file, int line);

//----------------------------------------------------------------------

#endif  //MY_STACK_H
