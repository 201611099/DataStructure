#ifndef STACK_LIST_H
# define STACK_LIST_H

# include "../../../week1/linked_list/list.h"

void		push_list(LinkedList *list, ListNode *data);
void		pop_list(LinkedList *list);
ListNode	*peek_list(LinkedList *list);

#endif