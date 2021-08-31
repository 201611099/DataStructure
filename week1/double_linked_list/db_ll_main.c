#include "./double_linked_list.h"

int main(void)
{
	DoubleLinkedList *d_list = createLinkedList();

	addLLElement(d_list, d_list->currentElementCount, createListNode(50));
	addLLElement(d_list, d_list->currentElementCount, createListNode(40));
	addLLElement(d_list, 0, createListNode(30));
	printf("======Initial List======\n");
	printLinkedList_head(d_list);

	removeLLElement(d_list, d_list->currentElementCount - 1);
	printf("\n======After remove index last======\n");
	printLinkedList_head(d_list);
	
	addLLElement(d_list, 1, createListNode(20));
	printf("\n======After insert index 1 data 20======\n");
	printLinkedList_head(d_list);
	printf("\n======reverse(tail)->Just print======\n");
	printLinkedList_tail(d_list);
	printf("length: %d\n", getLinkedListLength(d_list));

	clearLinkedList(d_list);
	printf("\n======After clear======\n");
	printLinkedList_head(d_list);
	printf("length: %d\n", getLinkedListLength(d_list));

	deleteLinkedList(d_list);
	printf("\n======After delete======\n");
	system("leaks a.out");
	system("rm a.out");
}