#ifndef LIST_H
# define LIST_H

# include "../utils/utils.h"

typedef int	t_data;

typedef struct	ListNodeType
{
	t_data				data; //int -> t_data
	struct ListNodeType	*pLink;
}	ListNode;

typedef struct	LinkedListType
{
	int			currentElementCount; // 현재 저장된 원소의 개수
	ListNode	*headerNode; // 헤더 노드(Header Node)
}	LinkedList;

LinkedList	*createLinkedList(void);
ListNode	*createListNode(t_data data);
t_bool		addLLElement(LinkedList *pList, int position, ListNode *element);
t_bool		addLLElementLast(LinkedList *pList, ListNode *element);
t_bool		removeLLElement(LinkedList *pList, int position);
t_data		getLLElement(LinkedList *pList, int position);

void		clearLinkedList(LinkedList *pList);
int			getLinkedListLength(LinkedList *pList);
void		deleteLinkedList(LinkedList *pList);
void		printLinkedList(LinkedList *pList);

#endif