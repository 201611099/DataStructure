#ifndef STACK_LIST_H
# define STACK_LIST_H

# include "../../../week1/linked_list/list.h"

t_bool		push_list(LinkedList *list, ListNode *data);
ListNode	*pop_list(LinkedList *list);
ListNode	*peek_list(LinkedList *list);

#endif