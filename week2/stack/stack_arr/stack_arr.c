#include "stack_arr.h"

void	push_arr(ArrayList *arr, ArrayListNode data)
{
	//if (isArrayListFull(arr)) // addALElement()함수에서 realloc해줄듯
	if (!arr)
	{
		printf("stack doesn't exist.\n");
		return ;
	}
	addALElement(arr, arr->currentElementCount, data);
}

void	pop_arr(ArrayList *arr)
{
	if (!arr)
	{
		printf("stack doesn't exist.\n");
		return ;
	}
	if (arr->currentElementCount == 0)
	{
		printf("pop: Empty stack(Underflow)\n");
		return ;
	}
	removeALElement(arr, arr->currentElementCount - 1);
}

ArrayListNode	peek_arr(ArrayList *arr)
{
	ArrayListNode tmp;

	tmp.data = 0;
	if (!arr)
	{
		printf("stack doesn't exist.\n");
		return (tmp);
	}
	if (arr->currentElementCount == 0)
	{ //exit함수 쓰지 말고 빈 스택인 경우 출력하려면 어떻게 해야할 지
		printf("peek: Empty stack\n");
		return (tmp);
	}
	return (arr->pElement[arr->currentElementCount - 1]);
}
