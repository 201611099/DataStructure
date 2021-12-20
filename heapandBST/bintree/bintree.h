#ifndef _BIN_TREE_
# define _BIN_TREE_

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct BinTreeNodeType
{
	char data; //데이터 값
	int visited; //방문했었는지

	struct BinTreeNodeType* pLeftChild; //왼쪽 자손
	struct BinTreeNodeType* pRightChild; // 오른쪽 자손 
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode; //루트노드
} BinTree;

// BinTreeNode makeBinTreeNode(char data);
BinTreeNode* makeBinTreeNode(char data);
BinTree* makeBinTree(BinTreeNode rootNode); //이진트리 생성
BinTreeNode* getRootNodeBT(BinTree* pBinTree); //루트 노드 포인터 반환
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

// #define TRUE		1
// #define FALSE		0

#endif