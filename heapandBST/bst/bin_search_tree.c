#include "./bin_search_tree.h"

// typedef struct BinSearchTreeNodeType
// {
// 	int key;
// 	char value;
// ​
// 	struct BinSearchTreeNodeType* pLeftChild;
// 	struct BinSearchTreeNodeType* pRightChild;
// } BinSearchTreeNode;
// ​
// typedef struct BinSearchTreeType
// {
// 	BinSearchTreeNode *pRootNode;
// } BinSearchTree;
// ​

BinSearchTree* createBinSearchTree(void)
{
	BinSearchTree *newBST;

	newBST = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (!newBST)
	{
		printf("Memory allocation error!\n");
		return (FALSE);
	}
	bzero(newBST, sizeof(BinSearchTree));
	return (newBST);
}

void	insertInternalElementBST(BinSearchTreeNode** root, BinSearchTreeNode *element)
 {
	if (*root == NULL)
		*root = element;
	else 
	{
		if ((*root)->key > element->key)
		{
			insertInternalElementBST(&((*root)->pLeftChild), element);
		}
		else
		{
			insertInternalElementBST(&((*root)->pRightChild), element);
		}
	}
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
	printf("%d\n", element.key);
	if (!pBinSearchTree)
	{
		printf("BST does not exist!\n");
		return (FALSE);
	}
	//검색연산 결과 NULL이면 insert가능
	if (searchBST(pBinSearchTree, element.key))
	{
		printf("Already exist\n");
		return (FALSE);
	}

	BinSearchTreeNode *newNode;

	newNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (!newNode)
	{
		printf("Memory allocation error!\n");
		return (FALSE);
	}
	*newNode = element;

	insertInternalElementBST(&(pBinSearchTree->pRootNode), newNode);
	return (TRUE);
}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key) // 키를 찾아서
{
	if (!pBinSearchTree)
	{
		printf("BST does not exist!\n");
		return (FALSE);
	}
	if (!(searchRecursiveBST(pBinSearchTree, key)))
		return (FALSE);
	// element검색 
	// 있으면 진행
	// del된 노드의 가장 오른쪽 자손이 del된 노드가 됨
	// 대체된 노드에 왼쪽 자손이 있으면 부모(위의 오른쪽 자손) 노드가 되고 왼쪽 자손이 지워짐
	
	//*검색하고 시작 

	BinSearchTreeNode *node;
	BinSearchTreeNode *sub_node;

	node = pBinSearchTree->pRootNode;
	while(node->key != key && node != NULL)
	{
		if (key < node->key)
			node = node->pLeftChild;
		else if (key > node->key)
			node = node->pRightChild;
	}

	sub_node = node;
	while(sub_node->pRightChild != NULL){
		sub_node = sub_node->pRightChild;
	}
	node->key = sub_node->key;
	if (sub_node->pLeftChild)
	{
		sub_node->key = sub_node->pLeftChild->key;
		free(sub_node->pLeftChild); 
	}
	else
	{	
	free(sub_node);
	}
	return (TRUE);
}


// // 삭제 연산
// // 1. 자식 없음 -> 그냥 삭제
//	 재산 환원
// // 2. 자식 하나(외동딸의 자손들) -> 자식을 올림 if (pLeftChild)
//	 parent->left? => parent->left->right->....->[left / right]이 재산 몰빵
//	 parent->right? => parent->right->left->....->[left / right]이 재산 몰빵
// // 3, 자식 둘(그 이상) -> 왼쪽서브트리에서 가장 큰 값 또는 오른쪽서브트리에서 가장 작은 값을 올리기
//	 parent->left->right->right->....->[left / right]
//	 단, 가장 오른쪽 자식의 왼쪽 자식이 있을 수 있다. 버려진 자식(왼쪽자식)이 생길 수 있음
//	 엄마/아빠의 출세로 인해 버려진 자신이 생기면 안되니까 할머니 오른쪽 자식으로 입양??
//	 vs
//	 parent->right->left->left->....->[left / right]
//	 단, 가장 왼쪽 자식의 오른쪽 자식이 있을 수 있다. 버려진 자식이 생길 수 있음
//	 엄마/아빠의 출세로 인해 버려진 자신이 생기면 안되니까 할머니 왼쪽 자식으로 입양
//	 who win?
//	 둘 중에 한 사람이 재산 다 갖기 (싸움은 아님, 둘 다 가능) < main event!

// 내일 hyojlee 님 하실 일 : 이걸 jae-kim님한테 설명하기 //

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key)
{
	if (!pBinSearchTree)
	{
		printf("BST does not exist!\n");
		return (NULL);
	}
	
	return (searchInternalRecursiveBST(pBinSearchTree->pRootNode, key));
}

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{
	if (!pTreeNode)
	{
		printf("The key does not exist.\n");
		return (0);
	}
	if (pTreeNode->key == key)
		return (pTreeNode);
	else if (pTreeNode->key < key)
		return (searchInternalRecursiveBST(pTreeNode->pRightChild, key));
	else if (pTreeNode->key > key)
		return (searchInternalRecursiveBST(pTreeNode->pLeftChild, key));
}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key) //iteration
{
	BinSearchTreeNode *cur;
	
	if (!pBinSearchTree)
	{
		printf("BST does not exist!\n");
		return (NULL);
	}
	cur = pBinSearchTree->pRootNode;
	while (cur)
	{
		if (cur->key == key)
		{
			printf("The key does not exist.\n");
			return (cur);
		}
		else if (cur->key < key)
			cur = cur->pRightChild;
		else
			cur = cur->pLeftChild;
	}
	return (NULL);
}

//void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
//{
//	if (!pBinSearchTree)
//	{
//		printf("BST does not exist!\n");
//		return ;
//	}
// if (pBinSearchTree->pRootNode)
//	{
//		deleteBinSearchTreeInternal(pBinSearchTree->pRootNode->pLeftChild);
//		deleteBinSearchTreeInternal(pBinSearchTree->pRootNode->pRightChild);
//	}

//void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
//{
//}