#ifndef DEQUE_H
# define DEQUE_H

# include "./double_linked_list.h"

typedef DoubleListNode    DequeNode;
typedef DoubleLinkedList  Deque;

t_bool  insertFront(Deque *deque, t_data data);
t_data  deleteFront(Deque *deque); //dequeue
t_data  getFront(Deque *deque);

t_bool  insertRear(Deque *deque, t_data data); //enqueue
t_data  deleteRear(Deque *deque);
t_data  getRear(Deque *deque);

#endif