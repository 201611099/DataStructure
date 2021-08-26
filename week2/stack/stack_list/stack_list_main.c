#include "stack_list.h"

int	main(void)
{
	LinkedList	*stack;

	stack = createLinkedList();
	if (!stack)
		return (1);

	push_list(stack, 10);
	push_list(stack, 20);
	push_list(stack, 30);
	push_list(stack, 40);
	push_list(stack, 50);

	printf("\n----------------stack(top->bottom)--------------\n");
	printLinkedList(stack);
	printf("stack top: %d\n", peek_list(stack));

	printf("stack pop: %d\n", pop_list(stack));
	printf("\n-----------stack after pop(top->bottom)---------\n");
	printLinkedList(stack);
	printf("stack top: %d\n", peek_list(stack));

	push_list(stack, 0);
	printf("\n-----------stack after push 0(top->bottom)---------\n");
	printLinkedList(stack);
	printf("stack top: %d\n", peek_list(stack));

	printf("stack pop: %d\n", pop_list(stack));
	printf("stack pop: %d\n", pop_list(stack));
	printf("stack pop: %d\n", pop_list(stack));
	printf("stack pop: %d\n", pop_list(stack));
	printf("stack pop: %d\n", pop_list(stack));
	printf("\n-----------stack after pop * 5(=> Empty stack)---------\n");
	printLinkedList(stack);
	pop_list(stack);
	deleteLinkedList(stack);
	//while (1);
	return (0);
}