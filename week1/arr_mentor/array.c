#include "array.h"

ArrayList	*createArrayList(int maxElementCount) //배열 생성
{
	ArrayList	*new;

	new = (ArrayList *)malloc(sizeof(ArrayList));
	if (!new)
		return (0);
	new->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!new->pElement)
	{
		free(new);
		return (0);
	}
	new->maxElementCount = maxElementCount;
	new->currentElementCount = 0;
	return (new);
}

void	deleteArrayList(ArrayList *pList) //배열 삭제
{
	free(pList->pElement);
	free(pList);
  pList->currentElementCount = 0;
  pList->maxElementCount = 0;
}

t_bool	isArrayListFull(ArrayList *pList) //배열 빈공간 있으면 FALSE, 없으면 TRUE
{
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	return (FALSE);
}

t_bool	addALElement(ArrayList *pList, int position, ArrayListNode element) //배열 원소 삽입
{ //position이 maxElementCount보다 터무니없이 큰 수면 current를 어떻게 줘야할 지
	ArrayListNode	*tmp;

	if (!pList)
		return (FALSE);
	if (position > pList->currentElementCount)
		position = pList->currentElementCount;
	if (position >= pList->maxElementCount)
	{
		tmp = realloc(pList->pElement, sizeof(ArrayListNode) * (position + 1));
		if (!tmp)
			return (FALSE);
		pList->pElement = tmp;
		pList->maxElementCount = position + 1;
	}
	if (isArrayListFull(pList))
	{
		pList->maxElementCount++;
		tmp = realloc(pList->pElement, sizeof(ArrayListNode) * (pList->maxElementCount));
		pList->pElement = tmp;
	}
	for (int i = pList->currentElementCount - 1; i >= position ; i--)
		pList->pElement[i + 1] = pList->pElement[i];
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

t_bool	removeALElement(ArrayList *pList, int position) //특정 인덱스 원소 삭제
{
	ArrayListNode	data;

	data.data = 0;
	if (!pList)
		return (FALSE);
	for (int i = position; i < pList->currentElementCount; i++)
	{
		if (i + 1 == pList->maxElementCount)
			pList->pElement[i] = data;
		else
			pList->pElement[i] = pList->pElement[i + 1];
	}
	pList->pElement[pList->currentElementCount - 1] = data;
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode	*getALElement(ArrayList *pList, int position) //특정 인덱스 데이터 가져오기
{
	return (&(pList->pElement[position]));
}

void	displayArrayList(ArrayList *pList) //배열 원소 출력
{
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("pList[%d] = %d\n", i, pList->pElement[i].data);
}

void	clearArrayList(ArrayList *pList) //배열 비우기
{
	ArrayListNode	data;

	data.data =0;
	for (int i = 0; i < pList->currentElementCount; i++)
		pList->pElement[i] = data;
	pList->currentElementCount = 0;
}

int	getArrayListLength(ArrayList *pList) //배열 길이 가져오기
{
	return (pList->currentElementCount);
}

int	getArrayListCapacity(ArrayList *pList) //배열 최대크기 가져오기
{
	return (pList->maxElementCount);
}