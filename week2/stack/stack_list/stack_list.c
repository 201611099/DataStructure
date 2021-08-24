#include "stack_list.h"

void  push_list(LinkedList *list, ListNode *data)
{
	if (!list)
	{
		printf("stack doesn't exist.\n");
		return ;
	}
	addLLElement(list, 0, data);
}

void  pop_list(LinkedList *list)
{
	if (!list)
	{
		printf("stack doesn't exist.\n");
		return ;
	}
	if (list->currentElementCount == 0)
	{
		printf("pop: Empty stack(Underflow)\n");
		return ;
	}
	removeLLElement(list, 0);
}

ListNode	*peek_list(LinkedList *list)
{
	if (!list)
	{
		printf("stack doesn't exist.\n");
		return (0);
	}
	if (list->currentElementCount == 0)
	{
		printf("peek: Empty stack\n");
		return (0);
	}
	return (list->headerNode);
}