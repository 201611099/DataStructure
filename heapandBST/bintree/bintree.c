#include "./bintree.h"

BinTreeNode* makeBinTreeNode(char data){
  BinTreeNode *ret;

  if(!(ret = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
     return 0;
  // ret->pLeftChild = NULL;
  // ret->pRightChild = NULL;
  bzero(ret, sizeof(BinTreeNode));
  ret->data = data;
  return ret;
}

BinTree* makeBinTree(BinTreeNode rootNode)
{
  BinTree *ret;

  if(!(ret = (BinTree *)malloc(sizeof(BinTree))))
    return 0;
  
  ret->pRootNode = makeBinTreeNode(rootNode.data);
  //free(&rootNode);
  // printf("alert:: %c %c", ret->pRootNode->data, rootNode.data);
  
  return ret;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
  if (!pBinTree)
    return NULL;
  // printf("root_get: %c\n", pBinTree->pRootNode->data);
  

  //Preorder_travrsal(pBinTree);
  return pBinTree->pRootNode;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
  if (!pParentNode)
    return NULL;
  // pParentNode->pLeftChild = makeBinTreeNode();
  pParentNode->pLeftChild = malloc(sizeof(BinTreeNode));

  *(pParentNode->pLeftChild) = element;
  
  // pParentNode->pLeftChild = &element;
  printf("test:: %c, %c, %c\n", pParentNode->data, pParentNode->pLeftChild->data, element.data);
 
  return pParentNode; 
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
  if (!pParentNode)
    return NULL;
  pParentNode->pRightChild = makeBinTreeNode(element.data);
  // printf("test:: %c, %c, %c\n", pParentNode->data, pParentNode->pRightChild->data, element.data);

  return pParentNode;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
  if (!pNode)
    return NULL;
  // printf("gParent: %c gLeft: %c\n", pNode->data, pNode->pLeftChild->data);
  return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
  if (!pNode)
    return NULL;
  // printf("parent %c right %c\n", pNode->data, pNode->pRightChild->data);
  return pNode->pRightChild;
}

void deleteBinTree(BinTree* pBinTree)
{
  if (!pBinTree)
    return ;
  deleteBinTreeNode(pBinTree->pRootNode);
  free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
  if (pNode == NULL)
    return ;
  deleteBinTreeNode(pNode->pLeftChild);
  deleteBinTreeNode(pNode->pRightChild);
  free(pNode);
}