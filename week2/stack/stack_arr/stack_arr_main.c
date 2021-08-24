#include "stack_arr.h"

int main(void)
{
	ArrayList *stack;
	ArrayListNode node;
	int max_cnt = 5;

	stack = createArrayList(max_cnt);
	node.data = 10;
	push_arr(stack, node);
	node.data = 20;
	push_arr(stack, node);
	node.data = 30;
	push_arr(stack, node);
	node.data = 40;
	push_arr(stack, node);
	node.data = 50;
	push_arr(stack, node);
	node.data = 60;
	push_arr(stack, node);

	printf("-------------------stack--------------------\n");
	displayArrayList(stack);
	printf(">>> capacity = %d\tlength = %d\n", getArrayListCapacity(stack), getArrayListLength(stack));
	printf("peek(stack top): %d\n\n", peek_arr(stack));

	printf("stack_pop: %d\n", pop_arr(stack));
	printf("--------------stack after pop---------------\n");
	displayArrayList(stack);
	printf(">>> capacity = %d\tlength = %d\n", getArrayListCapacity(stack), getArrayListLength(stack));

	printf("\npeek(stack top): %d\n", peek_arr(stack));
	printf("stack_pop: %d\n", pop_arr(stack));
	printf("stack_pop: %d\n", pop_arr(stack));
	printf("stack_pop: %d\n", pop_arr(stack));
	printf("stack_pop: %d\n", pop_arr(stack));
	printf("stack_pop: %d\n", pop_arr(stack));
	printf("------stack after pop * 5(Empty stack)------\n");
	printf(">>> capacity = %d\tlength = %d\n", getArrayListCapacity(stack), getArrayListLength(stack));
	displayArrayList(stack);
	printf("peek(stack top): %d\n\n", peek_arr(stack));

	printf("stack_pop: %d\n", pop_arr(stack));
	printf("------Empty stack after pop(Underflow)------\n");
	printf(">>> capacity = %d\tlength = %d\n", getArrayListCapacity(stack), getArrayListLength(stack));
	printf("peek(stack top): %d\n", peek_arr(stack));
	deleteArrayList(stack);
	return (0);
}