#include "./deque.h"

t_bool	insertFront(Deque *deque, t_data data)
{
	if (addLLElement(deque, 0, createListNode(data)) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_data	deleteFront(Deque *deque) //dequeue
{
	t_data	ret;

	ret = getLLElement(deque, 0); // ret = pList->headerNode.next->data;
	if (removeLLElement(deque, 0) == TRUE)
		return (ret);
	bzero(&ret, sizeof(t_data));
	return (ret);
}

t_data	getFront(Deque *deque)
{
	return (getLLElement(deque, 0));
}

t_bool	insertRear(Deque *deque, t_data data) //enqueue
{
	if (addLLElement(deque, deque->currentElementCount, createListNode(data)) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_data	deleteRear(Deque *deque)
{
	t_data	ret;
	ret = deque->tailNode.prev->data;
	if (removeLLElement(deque, deque->currentElementCount - 1) == TRUE)
		return (ret);
	bzero(&ret, sizeof(t_data));
	return (ret);
}

t_data	getRear(Deque *deque)
{
	return (deque->tailNode.prev->data);
}
