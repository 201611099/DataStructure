#include "./double_linked_list.h"

DoubleLinkedList	*createLinkedList(void)
{
	DoubleLinkedList	*d_list;

	d_list = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
	if (d_list == 0)
		return (0);
	bzero(d_list, sizeof(DoubleLinkedList));
	return (d_list);
}

DoubleListNode *createListNode(t_data data)
{
	DoubleListNode	*d_node;

	d_node = (DoubleListNode *)malloc(sizeof(DoubleListNode));
	if (d_node == 0)
		return (0);
	bzero(d_node, sizeof(DoubleListNode));
	d_node->data = data;
	return (d_node);
}

t_bool		addLLElement(DoubleLinkedList *pList, int position, DoubleListNode *element)
{
	DoubleListNode	*first;
	DoubleListNode	*cur;
	DoubleListNode	*last;

	if (pList->currentElementCount < position)
	{
		printf("유효범위 초과\n");
		free(element);
		return (FALSE);
	}
	if (pList->currentElementCount == 0 && position == 0) //최초 추가
	{
		pList->headerNode.next = element;
		pList->tailNode.prev = element;
	}
	else if (pList->currentElementCount == position) // 마지막 요소에 추가
	{
		last = pList->tailNode.prev;
		last->next = element;
		element->prev = last;
		pList->tailNode.prev = element;
	}
	else //current가 1개 이상
	{
		if (position == 0)
		{
			first = pList->headerNode.next;
			first->prev = element;
			element->next = first;
			pList->headerNode.next = element;
		}
		else //삽입위치 중간일 때
		{
			cur = pList->headerNode.next;
			for (int i = 0; i < position - 1; i++)
				cur = cur->next;
			element->next = cur->next;
			element->prev = cur;
			cur->next->prev = element;
			cur->next = element;
		}
	}
	pList->currentElementCount++;
	return (TRUE);
}

t_bool		removeLLElement(DoubleLinkedList *pList, int position)
{
	DoubleListNode *first;
	DoubleListNode *last;
	DoubleListNode *cur;

	if (pList == 0 || pList->currentElementCount == 0)
		return (FALSE);
	if (pList->currentElementCount - 1 < position)
		return (FALSE);
	if (position == 0)
	{
		first = pList->headerNode.next;
		if (pList->currentElementCount == 1)
		{
			pList->headerNode.next = NULL;
			pList->tailNode.prev = NULL;
		}
		else
		{
			pList->headerNode.next = first->next;
			first->next->prev = NULL;
			first->next = NULL;
		}
		free(first);
	}
	else if (pList->currentElementCount - 1 == position) 
	{
		last = pList->tailNode.prev;
		last->prev->next = NULL;
		pList->tailNode.prev = last->prev;
		last->prev = NULL;
		free(last);
	}
	else
	{
		cur = pList->headerNode.next;
		for (int i = 0; i < position; i++)
			cur = cur->next;
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		cur->next = NULL;
		cur->prev = NULL;
		free(cur);
	}
	pList->currentElementCount--;
	return (TRUE);
}

t_data		getLLElement(DoubleLinkedList *pList, int position)
{
	t_data	ret;
	DoubleListNode	*cur;

	bzero(&ret, sizeof(t_data));
	if (pList == 0 || pList->currentElementCount == 0 ||
			pList->currentElementCount <= position)
		return (ret); //return (0);
	cur = pList->headerNode.next;
	for (int i = 0; i < position; i++)
		cur = cur->next;
	ret = cur->data;
	return (ret);
}

void		clearLinkedList(DoubleLinkedList *pList)
{ //samin님 씽크빅
	if (pList == 0 || pList->currentElementCount == 0)
		return ;
	while (pList->currentElementCount != 0)
		removeLLElement(pList, 0);
	bzero(pList, sizeof(DoubleLinkedList));
}

int			getLinkedListLength(DoubleLinkedList *pList)
{
	if (pList == 0)
		return (0);
	return (pList->currentElementCount);
}

void		deleteLinkedList(DoubleLinkedList *pList)
{
	clearLinkedList(pList);
	free(pList);
}

void		printLinkedList_head(DoubleLinkedList *pList)
{
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("%d -> ", getLLElement(pList, i));
	printf("\n");
}

void		printLinkedList_tail(DoubleLinkedList *pList)
{
	DoubleListNode *cur;

	cur = pList->tailNode.prev;
	while (cur)
	{
		printf("%d -> ", cur->data);
		cur = cur->prev;
	}
	printf("\n");
}