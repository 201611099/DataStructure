#ifndef HEAP_H
# define HEAP_H

# define MAX_NUM	256
# define SIZE		8
# define TRUE		1
# define FALSE		0

# include <strings.h>
# include <stdio.h>
# include <stdlib.h>

typedef int element;

typedef struct HEAP {
	element	pElement[MAX_NUM];
	int		currentElementCount;
} Heap;

Heap	*createHeap(void); //heap생성
int		deleteHeap(Heap *heap); //heap삭제
int		insertMinHeap(Heap *heap, element data); //MinHeap 노드 추가
int		deleteMinHeap(Heap *heap); //MinHeap 노드 삭제
void	printSort(int *sorting, int size);
void	heapSortAsc(element *src, int size);
void	heapSortDesc(element *src, int size);

#endif