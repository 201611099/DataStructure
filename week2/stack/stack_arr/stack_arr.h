#ifndef STACK_ARR_H
# define STACK_ARR_H

//실행 gcc -I../../utils ../arr_mentor/array.c ../arr_mentor/array.h stack_arr.c stack_arr_main.c; ./a.out

# include "../../../week1/arr_mentor/array.h"

void			push_arr(ArrayList *arr, ArrayListNode data);
void			pop_arr(ArrayList *arr);
ArrayListNode	peek_arr(ArrayList *arr);

#endif
