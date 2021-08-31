#include "./deque.h"

int main(void)
{
	Deque *deque;
	
	deque = createLinkedList();
	if (!deque)
		return (1);
	insertFront(deque, 10);
	printf("getFront: %d\n", getFront(deque));
	printf("getRear: %d\n", getRear(deque));
	insertFront(deque, 20);
	insertRear(deque, 100);
	insertFront(deque, 30);
	insertFront(deque, 40);
	printf("\n======insertFront * 2 + insertRear * 1 + insertFront * 2======\n");
	printLinkedList_head(deque);

	printf("\ngetRear %d\n", getRear(deque));
	printf("deleteRear %d\n", deleteRear(deque));
	printf("\n======deleteRear======\n");
	printLinkedList_head(deque);
	
	printf("\ngetFront %d\n", getFront(deque));
	printf("deleteFront %d\n", deleteFront(deque));
	printf("\n======deleteFront======\n");
	printLinkedList_head(deque);

	clearLinkedList(deque);
	printf("\n======After clear======\n");
	printLinkedList_head(deque);

	deleteLinkedList(deque); //delete 후에는 프린트 불가능(deque자체가 없어졌으니까)
	system("leaks a.out");
	system("rm a.out");
}