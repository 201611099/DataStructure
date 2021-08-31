#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef int	t_data;

typedef struct	ListNodeType
{
	t_data				data; //int -> t_data
	struct ListNodeType	*prev;
	struct ListNodeType	*next;
}	DoubleListNode;

typedef struct	LinkedListType
{
	int				currentElementCount; // 현재 저장된 원소의 개수
	DoubleListNode	headerNode; // 헤더 노드(Header Node)
	DoubleListNode	tailNode; // 테일 노드(tail Node)
}	DoubleLinkedList;

DoubleLinkedList	*createLinkedList(void);
DoubleListNode		*createListNode(t_data data);
t_bool				addLLElement(DoubleLinkedList *pList, int position, DoubleListNode *element);
t_bool				removeLLElement(DoubleLinkedList *pList, int position);
t_data				getLLElement(DoubleLinkedList *pList, int position);

void				clearLinkedList(DoubleLinkedList *pList);
int					getLinkedListLength(DoubleLinkedList *pList);
void				deleteLinkedList(DoubleLinkedList *pList);
void				printLinkedList_head(DoubleLinkedList *pList);
void				printLinkedList_tail(DoubleLinkedList *pList);

#endif