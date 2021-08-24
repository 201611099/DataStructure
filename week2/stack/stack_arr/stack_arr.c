#include "stack_arr.h"

t_bool	push_arr(ArrayList *arr, ArrayListNode data)
{
	//if (isArrayListFull(arr)) // addALElement()함수에서 realloc해줄듯
	if (!arr)
	{
		printf("stack doesn't exist.\n");
		return (FALSE);
	}
	return (addALElement(arr, arr->currentElementCount, data));
}

int	pop_arr(ArrayList *arr)
{
	int	ret;

	if (!arr)
		return (0);
	if (arr->currentElementCount == 0)
		return (0);
	arr->currentElementCount--;
	ret = arr->pElement[arr->currentElementCount].data;
	bzero(&(arr->pElement[arr->currentElementCount]), sizeof(ArrayListNode));
	return (ret);
}

int	peek_arr(ArrayList *arr)
{
	if (!arr)
		return (0);
	if (arr->currentElementCount == 0)
		return (0);
	return (arr->pElement[arr->currentElementCount - 1].data);
}
