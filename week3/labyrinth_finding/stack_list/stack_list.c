#include "stack_list.h"

t_bool	push_list(LinkedList *list, t_data data)
{
	ListNode	*new;
  
	if (!list)
	{
		printf("stack doesn't exist.\n");
		return (FALSE);
	}
	new = createListNode(data);
	if (!new)
		return (FALSE);
	return (addLLElement(list, 0, new));
}

t_data	pop_list(LinkedList *list)
{
	t_data	cur;

  bzero(&cur, sizeof(t_data));
	if (!list)
	{
		printf("stack doesn't exist.\n");
		return (cur);
	}
	if (list->currentElementCount == 0)
	{
		printf("pop_error: Empty stack\n");
		return (cur);
	}
	cur = getLLElement(list, 0);
	removeLLElement(list, 0);
	return (cur);
}

t_data	peek_list(LinkedList *list)
{	
  t_data	cur;

  bzero(&cur, sizeof(t_data));
	if (!list)
	{
		printf("stack doesn't exist.\n");
		return (cur);
	}
	if (list->currentElementCount == 0)
	{
		printf("peek_error: Empty stack\n");
		return (cur);
	}
	return (getLLElement(list, 0));
}