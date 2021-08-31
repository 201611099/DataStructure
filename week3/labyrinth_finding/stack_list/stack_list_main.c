#include "stack_list.h"

int	main(void)
{
	LinkedList	*stack;
  t_data  data;

	stack = createLinkedList();
	if (!stack)
		return (1);
  data.x_pos = 1;
  data.y_pos = 0;
	push_list(stack, data);
	push_list(stack, data);
	push_list(stack, data);
	push_list(stack, data);
	push_list(stack, data);
	// push_list(stack, 20);
	// push_list(stack, 30);
	// push_list(stack, 40);
	// push_list(stack, 50);

	printf("\n----------------stack(top->bottom)--------------\n");
	printLinkedList(stack);
	printf("stack top: %d %d\n", peek_list(stack).x_pos, peek_list(stack).y_pos);

  t_data n1;
  n1 = pop_list(stack);
	printf("stack pop: %d %d\n", n1.x_pos, n1.y_pos);
	// printf("stack pop: %d\n", pop_list(stack));
	printf("\n-----------stack after pop(top->bottom)---------\n");
	printLinkedList(stack);
	printf("stack top: %d %d\n", peek_list(stack).x_pos, peek_list(stack).y_pos);
	// printf("stack top: %d\n", peek_list(stack));

	push_list(stack, data);
	printf("\n-----------stack after push 0(top->bottom)---------\n");
	printLinkedList(stack);
	printf("stack top: %d %d\n", peek_list(stack).x_pos, peek_list(stack).y_pos);
	// printf("stack top: %d\n", peek_list(stack));
  n1 = pop_list(stack);
	printf("stack pop: %d %d\n", n1.x_pos, n1.y_pos);
  n1 = pop_list(stack);
	printf("stack pop: %d %d\n", n1.x_pos, n1.y_pos);
  n1 = pop_list(stack);
	printf("stack pop: %d %d\n", n1.x_pos, n1.y_pos);
  n1 = pop_list(stack);
	printf("stack pop: %d %d\n", n1.x_pos, n1.y_pos);
  n1 = pop_list(stack);
	printf("stack pop: %d %d\n", n1.x_pos, n1.y_pos);
	// printf("stack pop: %d\n", pop_list(stack));
	// printf("stack pop: %d\n", pop_list(stack));
	// printf("stack pop: %d\n", pop_list(stack));
	// printf("stack pop: %d\n", pop_list(stack));
	printLinkedList(stack);
	// printf("stack pop: %d\n", pop_list(stack));
	printf("\n-----------stack after pop * 5(=> Empty stack)---------\n");
	printLinkedList(stack);
	pop_list(stack);
	deleteLinkedList(stack);
	//while (1);
	return (0);
}