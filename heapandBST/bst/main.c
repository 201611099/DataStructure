#include "./bin_search_tree.h"
// #include "../bintree/traversal/circular_queue.h"
#include "./circular_queue.h"

void Level_Traversal(BinSearchTreeNode *pNode)
{
  ArrayQueue *queue;
  t_data  data;

  if (!pNode)
    return; 
  queue = createArrayQueue(100);
  enqueue(queue, *pNode);
  while (is_empty(queue) == FALSE)
  {
    data = dequeue(queue);
    pNode = &data;
    printf(" %d ", pNode->key);
		if (pNode->pLeftChild)
			enqueue(queue, *(pNode->pLeftChild));
		if (pNode->pRightChild)
			enqueue(queue, *(pNode->pRightChild));
  }
}

int main(void)
{
  BinSearchTree *bst = createBinSearchTree();
  BinSearchTreeNode node[10];
  bzero(&node[0], sizeof(BinSearchTreeNode));
//  node[0].key = 10;
//  printf("main 32 %d\n", insertElementBST(bst, node[0]));
  if (!bst->pRootNode)
    printf("main 34 root NULL\n");
   for (int i = 0; i < 10; i++)
   {
     bzero(&node[i], sizeof(BinSearchTreeNode));
     node[i].key = 10 * i + i;
     if (i % 3 == 0)
      node[i].key *= -1;
     if (i < 5)
       insertElementBST(bst, node[i]);
   }
  node[5].key = -10;
  insertElementBST(bst, node[5]);
  Level_Traversal(bst->pRootNode);
  /*
        0
    -33   11
  -10       22
              44  
  */
  
  BinSearchTreeNode *sc;
  // RecursiveBST 찾은 경우
  sc = searchRecursiveBST(bst, 11);
  if (!sc)
    printf("\n[recursive] No data\n");
  else
    printf("\n[recursive] %d\n", sc->key);

  // RecursiveBST 못 찾은 경우
  sc = searchRecursiveBST(bst, -100);
  if (!sc)
    printf("[recursive] No data\n");
  else
    printf("[recursive] %d\n", sc->key);

  // nonRecursiveBST 찾은 경우
  sc = searchBST(bst, 11);
  if (!sc)
    printf("[iteration] No data\n");
  else
    printf("[iteration] %d\n", sc->key);

  // nonRecursiveBST 못 찾은 경우
  sc = searchBST(bst, -100);
  if (!sc)
    printf("[iteration] No data\n");
  else
    printf("[iteration] %d\n", sc->key);

    Level_Traversal(bst->pRootNode);
    deleteElementBST(bst, 44);
     Level_Traversal(bst->pRootNode);
    // deleteElementBST(bst, 144);
}