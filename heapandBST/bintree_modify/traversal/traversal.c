#include "./traversal.h"

void Preorder_Traversal(BinTreeNode *pNode)
{
  if (!pNode)
    return;
  printf(" %c ", pNode->data);
  Preorder_Traversal(pNode->pLeftChild);
  Preorder_Traversal(pNode->pRightChild);
}

void Inorder_Traversal(BinTreeNode *pNode)
{
  if (!pNode)
    return;
  Inorder_Traversal(pNode->pLeftChild);
  printf(" %c ", pNode->data);
  Inorder_Traversal(pNode->pRightChild);
}

void Postorder_Traversal(BinTreeNode *pNode)
{
  if (!pNode)
    return;
  Postorder_Traversal(pNode->pLeftChild);
  Postorder_Traversal(pNode->pRightChild);
  printf(" %c ", pNode->data);
}

void Level_Traversal(BinTreeNode *pNode)
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
    printf(" %c ", pNode->data);
		if (pNode->pLeftChild)
			enqueue(queue, *(pNode->pLeftChild));
		if (pNode->pRightChild)
			enqueue(queue, *(pNode->pRightChild));
  }
}