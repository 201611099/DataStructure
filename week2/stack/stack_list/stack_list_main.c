#include "stack_list.h"

int	main(void)
{
	LinkedList	*stack;
	ListNode	*node1;
	ListNode	*node2;
	ListNode	*node3;
	ListNode	*node4;
	ListNode	*node5;

	stack = createLinkedList();
	if (!stack)
		return (1);
	
	node1 = createListNode(10);
	node2 = createListNode(-20);
	node3 = createListNode(30);
	node4 = createListNode(-40);
	node5 = createListNode(50);

	push_list(stack, node1);
	push_list(stack, node2);
	push_list(stack, node3);
	push_list(stack, node4);
	push_list(stack, node5);

	printf("\n----------------stack(top->bottom)--------------\n");
	printLinkedList(stack);
	printf("stack top: %d\n", peek_list(stack)->data);

	pop_list(stack);
	printf("\n-----------stack after pop(top->bottom)---------\n");
	printLinkedList(stack);
	printf("stack top: %d\n", peek_list(stack)->data);

	node5 = createListNode(0);
	push_list(stack, node5);
	printf("\n-----------stack after push 0(top->bottom)---------\n");
	printLinkedList(stack);
	printf("stack top: %d\n", peek_list(stack)->data);

	pop_list(stack);
	pop_list(stack);
	pop_list(stack);
	pop_list(stack);
	pop_list(stack);
	printf("\n-----------stack after pop * 5(=> Empty stack)---------\n");
	printLinkedList(stack);
	pop_list(stack);
	deleteLinkedList(stack);
	return (0);
}