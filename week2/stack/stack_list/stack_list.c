#include "stack_list.h"

t_bool	push_list(LinkedList *list, ListNode *data)
{
	if (!list)
	{
		printf("stack doesn't exist.\n");
		return (FALSE);
	}
	return (addLLElement(list, 0, data));
}

ListNode	*pop_list(LinkedList *list)
{
	ListNode	*cur;

	if (!list)
		return (0);
	if (list->currentElementCount == 0)
		return (0);
	cur = list->headerNode;
	list->headerNode = cur->pLink;
	cur->pLink = 0;
	list->currentElementCount--;
	return (cur);
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