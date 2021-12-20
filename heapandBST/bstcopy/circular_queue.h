#ifndef CIRCULAR_QUEUE_H
# define CIRCULAR_QUEUE_H

# include "./bin_search_tree.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef enum	e_bool
{
	FALSE1,
	TRUE1
}	t_bool;

typedef enum	SimStatusType
{
  none, //도착 전
	arrival, //도착상태
	start, //시작(서비스 중)
	end //서비스 끝
}	SimStatus;

//typedef char	t_data;
// typedef struct BinTreeNodeType
// {
// 	char data; //데이터 값
// 	int visited; //방문했었는지

// 	struct BinTreeNodeType* pLeftChild; //왼쪽 자손
// 	struct BinTreeNodeType* pRightChild; // 오른쪽 자손 
// } BinTreeNode;

typedef BinSearchTreeNode t_data;


typedef struct ArrayQueueNodeType
{
	t_data	element; //문자 자료
}	ArrayQueueNode;

typedef struct ArrayQueueType
{
  int				maxElementCount; //최대 노드 개수
  int				currentElementCount; //현재 노드 개수
  ArrayQueueNode	*pElement; //노드 저장을위한 배열 포인터
  int				front; //제일 처음부분(삭제 연산(dequeue) 발생)
  int				rear; //제일 뒷부분(삽입 연산(enqueue) 발생)
} ArrayQueue;

ArrayQueue	*createArrayQueue(int maxElementCount);

t_bool		enqueue(ArrayQueue *queue, t_data data);
t_data		peek(ArrayQueue *queue);
t_data		dequeue(ArrayQueue *queue);
t_bool		is_empty(ArrayQueue *queue);
t_bool		is_full(ArrayQueue *queue);

void		display_queue(ArrayQueue *queue);
void		delete_queue(ArrayQueue *queue);

#endif
