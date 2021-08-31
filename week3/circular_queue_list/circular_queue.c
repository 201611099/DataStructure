#include "./circular_queue.h"

t_bool	enqueue(Queue *queue, t_data data)
{
	if (!queue)
		return (FALSE);
	return (addLLElement(queue, 0, createListNode(data)));
}

t_data	dequeue(Queue *queue)
{
	t_data	ret;

	ret = getLLElement(queue, queue->currentElementCount - 1);
	removeLLElement(queue, queue->currentElementCount - 1);
	return (ret);
}

t_data	peek(Queue *queue)
{
	t_data	ret;
	
	ret = getLLElement(queue, queue->currentElementCount - 1);
	return (ret);
}

t_bool is_empty(Queue *queue)
{
	if (queue->currentElementCount== 0)
		return (TRUE);
	return (FALSE);
}


