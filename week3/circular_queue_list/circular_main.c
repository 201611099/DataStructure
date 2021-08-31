#include "./circular_queue.h"

int	main()
{
	Queue *queue = createLinkedList();

	printf("is_empty: %s\n", is_empty(queue) == TRUE ? "True" : "False");

	for (int i = 10; i <= 100; i += 10)
		enqueue(queue, i);

	printLinkedList(queue);
	printf("is_empty: %s\n", is_empty(queue) == TRUE ? "True" : "False");

	printf("curElementCount %d\n", queue->currentElementCount);

	for (int i = 0; i < 2; i++)
		printf("dequeue : %d\n", dequeue(queue)); 
	printf("curElementCount %d\n", queue->currentElementCount);
	printLinkedList(queue);

	printf("peek: %d\n", peek(queue));

	int count = queue->currentElementCount;
	for (int i = 0; i < count; i++)
		printf("dequeue : %d\n", dequeue(queue)); 
	// clearLinkedList(queue);
	printf("curElementCount %d\n", queue->currentElementCount);

	printLinkedList(queue);

	printf("is_empty: %s\n", is_empty(queue) == TRUE ? "True" : "False");
	deleteLinkedList(queue);
	system("leaks a.out");
	system("rm a.out");
}
