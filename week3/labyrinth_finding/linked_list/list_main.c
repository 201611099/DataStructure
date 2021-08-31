#include "list.h"

int	main(void)
{
	LinkedList	*lst;
	ListNode	*node1;
	ListNode	*node2;
	ListNode	*node3;
	ListNode	*node4;
	ListNode	*node5;
  t_data  data;

  data.x_pos = 1;
  data.y_pos = 0;
	lst = createLinkedList();
	if (!lst)
		return (1);
	node1 = createListNode(data);
  data.x_pos = 2;
	node2 = createListNode(data);
  data.x_pos = 3;
	node3 = createListNode(data);
  data.x_pos = 4;
	node4 = createListNode(data);
  data.x_pos = 5;
	node5 = createListNode(data);
	addLLElement(lst, lst->currentElementCount, node1);
	addLLElement(lst, lst->currentElementCount, node2);
	addLLElement(lst, lst->currentElementCount, node3);
	addLLElement(lst, lst->currentElementCount, node4);
	addLLElement(lst, lst->currentElementCount, node5);
	printf("\n----------print list----------\n");
	printLinkedList(lst);

	printf("\nposition %d: %d %d\n", 2, getLLElement(lst, 2).x_pos, getLLElement(lst, 2).y_pos);

	printf("\nposition %d: %d %d\n", 0, getLLElement(lst, 0).x_pos, getLLElement(lst, 0).y_pos);


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
	// printLinkedList(lst);
	// printf("\nLength %d\n", getLinkedListLength(lst));
  // system("leaks a.out");
	return (0);
}
