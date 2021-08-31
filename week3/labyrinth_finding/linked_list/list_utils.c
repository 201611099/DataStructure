#include "list.h"

void	printLinkedList(LinkedList *pList)
{
	ListNode	*cur;

	if (!pList || !pList->currentElementCount)
		return ;
	cur = pList->headerNode;
	while (cur)
	{
		// printf("[ %d | %d | %d ] -> ", cur->data.x_pos, cur->data.y_pos, cur->data.dir);
		printf("(%d, %d) <- ", cur->data.x_pos, cur->data.y_pos);
		cur = cur->pLink;
	}
	printf("\b\b\b\b    \n");
}