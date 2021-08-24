#ifndef STACK_ARR_H
# define STACK_ARR_H

//실행 gcc -I../../utils ../arr_mentor/array.c ../arr_mentor/array.h stack_arr.c stack_arr_main.c; ./a.out

# include "../../../week1/arr_mentor/array.h"

t_bool	push_arr(ArrayList *arr, ArrayListNode data);
int		pop_arr(ArrayList *arr);
int		peek_arr(ArrayList *arr);

#endif
