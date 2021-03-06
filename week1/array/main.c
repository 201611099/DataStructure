#include "array.h"

int main(void)
{
	//char *str;

	//str = (char *)malloc(sizeof(char) * 10);
	//*str = 65;
	//str++;
	//*str = 100;
	//str++;
	//*str = '\0';
	//str -= 2;
	//printf("%s\n", str);
	//free(str);
	ArrayList *arr;

	ArrayListNode data;

	arr = createArrayList(4);
	if (!arr)
		return (1);
	data.data = 10;
	addALElement(arr, 0, data);
	data.data = 20;
	addALElement(arr, 1, data);
	data.data = 30;
	addALElement(arr, 2, data);
	data.data = 40;
	addALElement(arr, 3, data);
	data.data = 50;
	addALElement(arr, 4, data);

	printf("array_length(size): %d\n", getArrayListLength(arr));
	printf("number of element: %d\n", arr->currentElementCount);
	printf("\n\n------------print array-------------\n");
	displayArrayList(arr);
	if (isArrayListFull(arr) == TRUE)
		printf("Array is full.\n");
	else
		printf("Array is not full.\n");

	printf("\narr[3] = %d\n", getALElement(arr, 3)->data);

	removeALElement(arr, 3);
	removeALElement(arr, 1);
	printf("\n\n------------remove idx 1 & 3-------------\n");
	printf("array_length(size): %d\n", getArrayListLength(arr));
	printf("number of element: %d\n", arr->currentElementCount);
	displayArrayList(arr);
	if (isArrayListFull(arr) == TRUE)
		printf("Array is full.\n");
	else
		printf("Array is not full.\n");

	printf("\n\n------------clear array-------------\n");
	clearArrayList(arr);
	displayArrayList(arr);

	deleteArrayList(arr);
	displayArrayList(arr);

	//while (1);
}
