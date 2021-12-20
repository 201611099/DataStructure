#ifndef _BIN_SEARCH_TREE_
# define _BIN_SEARCH_TREE_

# include <stdio.h>
# include <strings.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE  0

typedef struct BinSearchTreeNodeType
{
	int key;
	char value;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

typedef struct BinSearchTreeType
{
	BinSearchTreeNode *pRootNode;
} BinSearchTree;

BinSearchTree* createBinSearchTree(void);
int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element);
int deleteElementBST(BinSearchTree* pBinSearchTree, int key);

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key); //Tree를 넘겨서 internal 호출
BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key);
BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key); //iteration으로 구현

// root = pBintree->root;

// while ()
// {
//   if (key == root->left || root->right)
//     break;
//   if (key < root->left)
//     root = root->left;
//   if (key > root->right)
//     root = root->right;
// }

// // 삭제 연산
// // 1. 자식 없음 -> 그냥 삭제
//   재산 환원
// // 2. 자식 하나(외동딸의 자손들) -> 자식을 올림 if (pLeftChild)
//   parent->left? => parent->left->right->....->[left / right]이 재산 몰빵
//   parent->right? => parent->right->left->....->[left / right]이 재산 몰빵

//                   30
//           20            40
//     10        24     34     46
//   6   14   22

// // 3, 자식 둘(그 이상) -> 왼쪽서브트리에서 가장 큰 값 또는 오른쪽서브트리에서 가장 작은 값을 올리기
//   parent->left->right->right->....->[left / right]
//   단, 가장 오른쪽 자식의 왼쪽 자식이 있을 수 있다. 버려진 자식(왼쪽자식)이 생길 수 있음
//   엄마/아빠의 출세로 인해 버려진 자신이 생기면 안되니까 할머니 오른쪽 자식으로 입양??
//   vs
//   parent->right->left->left->....->[left / right]
//   단, 가장 왼쪽 자식의 오른쪽 자식이 있을 수 있다. 버려진 자식이 생길 수 있음
//   엄마/아빠의 출세로 인해 버려진 자신이 생기면 안되니까 할머니 왼쪽 자식으로 입양
//   who win?
//   둘 중에 한 사람이 재산 다 갖기 (싸움은 아님, 둘 다 가능) < main event!

void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);

#endif