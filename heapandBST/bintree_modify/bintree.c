#include "./bintree.h"

BinTreeNode* makeBinTreeNode(char data){
  BinTreeNode *ret;

  if(!(ret = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
     return 0;
//   bzero(ret, sizeof(BinTreeNode));
  ret->pLeftChild = NULL;
  ret->pRightChild = NULL;
  ret->data = data;
  return ret;
}

BinTree* makeBinTree(BinTreeNode *rootNode)
{
  BinTree *ret;

  if(!(ret = (BinTree *)malloc(sizeof(BinTree))))
    return 0;
  ret->pRootNode = rootNode;
  return ret;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
  if (!pBinTree)
    return NULL;

  return pBinTree->pRootNode;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element)
{
  if (!pParentNode)
    return NULL;
    pParentNode->pLeftChild = element;
  return pParentNode; 
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode *element)
{
  if (!pParentNode)
    return NULL;
  pParentNode->pRightChild = element;
  return pParentNode;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
  if (!pNode)
    return NULL;
  return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
  if (!pNode)
    return NULL;
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