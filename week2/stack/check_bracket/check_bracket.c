#include "../stack_list/stack_list.h"

static t_bool	checkMatching(LinkedList *stack, int bracket)
{
	ListNode	*top;

	if (stack->currentElementCount == 0)
	{
		deleteLinkedList(stack);
		return (FALSE);
	}
	top = peek_list(stack);
	pop_list(stack);
	if (!top || top->data != bracket)
	{
		deleteLinkedList(stack);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	checkBracketMatching(char *exp)
{
	LinkedList	*stack;
	int			idx;

	idx = 0;
	stack = createLinkedList();
	if (!stack)
		return (FALSE);
	while (exp[idx])
	{
		switch (exp[idx])
		{
		case '(':
		case '[':
		case '{':
			push_list(stack, createListNode(exp[idx]));
			break;
		case ')':
			if (checkMatching(stack, '(') == FALSE)
				return (FALSE);
			break;
		case ']':
			if (checkMatching(stack, '[') == FALSE)
				return (FALSE);
			break;
		case '}':
			if (checkMatching(stack, '{') == FALSE)
				return (FALSE);
			break;
		default:
			break;
		}
		idx++;
	}
	deleteLinkedList(stack);
	return (TRUE);
}
