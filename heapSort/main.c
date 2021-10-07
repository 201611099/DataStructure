#include "./heap.h"

int main(void){
	element data[SIZE] = {20, 10, 30, 50, 80, 60, 40, 70};

	heapSortAsc(data, SIZE);
	printf("\n==== Ascending ====\x1b[33m\n");
	printSort(data, SIZE);
	heapSortDesc(data, SIZE);
	printf("\n==== Descending ====\x1b[36m\n");
	printSort(data, SIZE);

	//system("leaks a.out");
	return (0);
}