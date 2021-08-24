#include "list.h"

int	main(void)
{
	LinkedList	*lst;
	ListNode	*node1;
	ListNode	*node2;
	ListNode	*node3;
	ListNode	*node4;
	ListNode	*node5;
	ListNode	*node6;

	lst = createLinkedList();
	if (!lst)
		return (1);
	node1 = createListNode(10);
	node2 = createListNode(-20);
	node3 = createListNode(30);
	node4 = createListNode(-40);
	node5 = createListNode(50);
	addLLElement(lst, lst->currentElementCount, node1);
	addLLElement(lst, lst->currentElementCount, node2);
	addLLElement(lst, lst->currentElementCount, node3);
	addLLElement(lst, lst->currentElementCount, node4);
	addLLElement(lst, lst->currentElementCount, node5);
	printf("\n----------print list----------\n");
	printLinkedList(lst);

	printf("\nposition %d: %d\n", 2, getLLElement(lst, 2)->data);
	printf("\nposition %d: %d\n", 0, getLLElement(lst, 0)->data);
	printf("\nposition %d: %d\n", 4, getLLElement(lst, 4)->data);
	printf("\nLength %d\n", getLinkedListLength(lst));

	node6 = createListNode(0);
	addLLElement(lst, 0, node6);
	printf("\n----------insert index 1 -> 0 list----------\n");
	printLinkedList(lst);

	printf("\nposition %d: %d\n", 2, getLLElement(lst, 2)->data);
	printf("\nposition %d: %d\n", 0, getLLElement(lst, 0)->data);
	printf("\nposition %d: %d\n", 4, getLLElement(lst, 4)->data);
	printf("\nLength %d\n", getLinkedListLength(lst));

	removeLLElement(lst, 0);
	printf("\n----------remove index 0----------\n");
	printLinkedList(lst);
	printf("\nLength %d\n", getLinkedListLength(lst));

	clearLinkedList(lst);
	printf("\n----------clear list----------\n");
	printLinkedList(lst);
	printf("\nLength %d\n", getLinkedListLength(lst));

	deleteLinkedList(lst);
	printf("\n----------delete list----------\n");
	printLinkedList(lst);
	printf("\nLength %d\n", getLinkedListLength(lst));
	return (0);
}
