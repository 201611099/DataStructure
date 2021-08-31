#include "reverse_list.h"

int	main(void)
{
	LinkedList	*lst;
	
	lst = createLinkedList();
	if (!lst)
		return (1);
	addLLElement(lst, 0, createListNode(10));
	addLLElement(lst, 1, createListNode(20));
	addLLElement(lst, 2, createListNode(30));
	addLLElement(lst, 3, createListNode(40));
	printf("========Initial List========\n");
	printLinkedList(lst);

	addLLElement(lst, 0, createListNode(0));
	printf("\n========Insert index 0 data 0========\n");
	printLinkedList(lst);

	reverseList(lst);
	printf("\n========Reverse List========\n");
	printLinkedList(lst);

	addLLElement(lst, 4, createListNode(5));
	printf("\n========Insert index 4 data 5========\n");
	printLinkedList(lst);

	clearLinkedList(lst);
	printf("\n========Clear List========\n");
	printLinkedList(lst);
	printf("currentElementCount: %d\n", lst->currentElementCount);

	deleteLinkedList(lst);
	//system("leaks a.out");
}