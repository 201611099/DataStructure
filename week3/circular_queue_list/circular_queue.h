#ifndef CIRCULAR_QUEUE_H
# define CIRCULAR_QUEUE_H

# include "./list.h"

typedef ListNode	Node;
typedef LinkedList	Queue;

t_bool	enqueue(Queue *queue, t_data data);

t_data	dequeue(Queue *queue);

t_data	peek(Queue *queue);

t_bool	is_empty(Queue *queue);

#endif