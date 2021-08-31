#include "reverse_list.h"

t_bool	reverseList(LinkedList	*lst)
{
	ListNode	*cur;
	ListNode	*pre;
	ListNode	*next;

	if (!lst)
		return (FALSE);
	cur = lst->headerNode;
	pre = NULL;
	while (cur)
	{
		next = cur->pLink;
		cur->pLink = pre;
		pre = cur;
		cur = next;
	}
	lst->headerNode = pre;
	return (TRUE);
}