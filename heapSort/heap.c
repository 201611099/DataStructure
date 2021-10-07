#include "./heap.h"

Heap	*createHeap(void) {
	Heap	*newHeap;

	newHeap = (Heap *)malloc(sizeof(Heap));
	if (!newHeap)
	{
		printf("Memory allocation error!\n");
		return (NULL);
	}
	bzero(newHeap, sizeof(Heap));
	return (newHeap);
}

int	insertMinHeap(Heap *heap, element data) { 
	int i;

// NULL guard
	if (!heap)
	{
		printf("Heap does not exist!\n");
		return (FALSE);
	}
// Step-1) 트리의 마지막 자리에 임시 저장 
	heap->currentElementCount = heap->currentElementCount + 1;
	i = heap->currentElementCount;
// Step-2) 부모 노드와 키 값 비교 및 이동 
	while ((i != 1) && (data < heap->pElement[i / 2]))
	{
		heap->pElement[i] = heap->pElement[i / 2];
		i = i / 2;
	}
	heap->pElement[i] = data;
	return (TRUE);
}

int	deleteMinHeap(Heap *heap) //삭제는 항상 루트노드에서
{
	int parent = 1;
	int child = 2;
	int tmp = heap->pElement[heap->currentElementCount];

	// NULL guard
	if (!heap)
	{
		printf("Heap does not exist!\n");
		return (FALSE);
	}
	// 1 루트 삭제
	// 2 마지막 인덱스 값 루트로 이동
	// heap->pElement[1] = heap->pElement[heap->currentElementCount];
	heap->currentElementCount--;
	// 키 값 비교하면서 reordering
	// = 이 들어가야하는 이유 : 내 형제와의 상속 issue <<
	while (child <= heap->currentElementCount)
	{
		if ((child < heap->currentElementCount) 
		&& heap->pElement[child] > heap->pElement[child + 1])
			child += 1;
		if (tmp <= heap->pElement[child])
			break ;
		heap->pElement[parent] = heap->pElement[child];
		parent = child;
		child *= 2;
	}
	heap->pElement[parent] = tmp;
	return (TRUE);
}

int deleteHeap(Heap *heap)
{
	if (!heap)
	{
		printf("Heap does not exist!\n");
		return (FALSE);
	}
	free(heap);
	heap = NULL;
	return (TRUE);
}

void	heapSortDesc(element *src, int size)
{
	Heap *heap = createHeap();

	for (int i = 0; i < size; i++)
		insertMinHeap(heap, src[i]);
	while (heap->currentElementCount)
	{
		src[heap->currentElementCount - 1] = heap->pElement[1];
		deleteMinHeap(heap);
	}
	deleteHeap(heap);
}

void	heapSortAsc(element *src, int size)
{
	Heap *heap = createHeap();
	int	initSize;

	for (int i = 0; i < size; i++)
		insertMinHeap(heap, src[i]);
	initSize = heap->currentElementCount;
	for (int i = 0; i < initSize; i++)
	{
		src[i] = heap->pElement[1];
		deleteMinHeap(heap);
	}
	deleteHeap(heap);
}

void	printSort(int *sorting, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", sorting[i]);
	printf("\x1b[0m\n\n");
}