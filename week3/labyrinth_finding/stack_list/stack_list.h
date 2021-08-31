#ifndef STACK_LIST_H
# define STACK_LIST_H

# include "../linked_list/list.h"

t_bool	push_list(LinkedList *list, t_data data);
t_data	pop_list(LinkedList *list);
t_data	peek_list(LinkedList *list);

#endif