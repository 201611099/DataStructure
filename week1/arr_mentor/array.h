#ifndef ARRAY_H
# define ARRAY_H

# include "../utils/utils.h"

typedef struct	ArrayListNodeType
{
	int	data;
}	ArrayListNode;

typedef struct	ArrayListType
{
	int		maxElementCount; //배열 사이즈
	int		currentElementCount; //저장된 원소의 개수
	ArrayListNode	*pElement; //1차원 배열
}	ArrayList;

ArrayList		*createArrayList(int maxElementCount); //배열 생성
void			deleteArrayList(ArrayList *pList); //배열 삭제
t_bool			isArrayListFull(ArrayList *pList); //배열 빈공간 있으면 FALSE, 없으면 TRUE
t_bool			addALElement(ArrayList *pList, int position, ArrayListNode element); //배열 원소 삽입
t_bool			removeALElement(ArrayList *pList, int position); //특정 인덱스 원소 삭제
ArrayListNode	*getALElement(ArrayList *pList, int position); //특정 인덱스 데이터 가져오기
void			displayArrayList(ArrayList *pList); //배열 원소 출력
void			clearArrayList(ArrayList *pList); //배열 비우기
int				getArrayListLength(ArrayList *pList); //배열 길이 가져오기
int	      getArrayListCapacity(ArrayList *pList); //배열 최대크기 가져오기

#endif