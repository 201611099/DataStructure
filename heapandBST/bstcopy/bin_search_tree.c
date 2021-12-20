#include "./bin_search_tree.h"

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

void	insertInternalElementBST(BinSearchTreeNode **parent, BinSearchTreeNode *newNode)
 {
	if (*parent == NULL)
		*parent = newNode;
	else 
	{
		if ((*parent)->key > newNode->key)
			insertInternalElementBST(&((*parent)->pLeftChild), newNode);
		else
			insertInternalElementBST(&((*parent)->pRightChild), newNode);
	}
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
	BinSearchTreeNode *newNode;

	if (!pBinSearchTree)
	{
		printf("[Insert Fail]: BST does not exist!\n");
		return (FALSE);
	}
	if (searchBST(pBinSearchTree, element.key)) //검색연산 결과있으면 insert 불가능
	{
		printf("[Insert Fail]: Already exists.\n");
		return (FALSE);
	}
	newNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (!newNode)
	{
		printf("[Insert Fail]: Memory allocation error!\n");
		return (FALSE);
	}
	*newNode = element;
	insertInternalElementBST(&(pBinSearchTree->pRootNode), newNode); //내부 재귀 호출
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

int deleteElementBST(BinSearchTree* pBinSearchTree, int key) // 키를 찾아서
{
	BinSearchTreeNode *dest;
	BinSearchTreeNode *parent;
	BinSearchTreeNode *cur;

	if (!pBinSearchTree)
	{
		printf("[Delete Fail]: BST does not exist!\n");
		return (FALSE);
	}
	dest = searchBST(pBinSearchTree, key);
	if (!dest) // 검색 결과 존재하지 않으면 삭제 불가
	{
		printf("[Delete Fail]: The key does not exist.\n");
		return (FALSE);
	}
	parent = searchParentBST(pBinSearchTree, key);
	// 1. 자식 노드가 없다면
	// 1-1. 루트노드라면(부모노드 존재X)
	// 1-2. 부모노드가 존재한다면
	if (dest->pLeftChild == NULL && dest->pRightChild == NULL)
	{
		if (parent != dest) //부모가 존재한다면 부모의 자식 포인터를 null로 만들어줘야한다.
		{
			if (parent->pLeftChild == dest)
				parent->pLeftChild = NULL;
			else
				parent->pRightChild = NULL;
		}
		free(dest);
	}
	// 2. 왼쪽 자식 노드가 존재한다면
	else if (dest->pLeftChild)
	{
		cur = dest->pLeftChild; //왼쪽으로 가서 가장 큰 값을 가져와야함 (찾고자 하는 값의 자식)
		while (cur->pRightChild) //왼쪽 서브트리의 가장 마지막 오른쪽 자식이 cur가 되도록
		{
			parent = cur;
			cur = cur->pRightChild;
		}
		if (cur != dest->pLeftChild) //dest의 왼쪽(cur)에 오른쪽 자식이 존재함.
		{ //가장 오른쪽 마지막 리프노드가 cur
			if (cur->pLeftChild)
				parent->pRightChild = cur->pLeftChild; //cur가 지워지고 cur의 왼쪽 자식이 cur 자리로 올라옴
			else
				parent->pRightChild = NULL;
			dest->key = cur->key; //dest에 왼쪽 서브트리의 가장 큰 키 값을 넣어줌 dest->value = cur->value;
			free(cur);
		}
		else //cur에 오른쪽이 없었다 내(cur)가 올라가야 한다.
		{ //cur == dest->pLeftChild
			if (parent->pRightChild == dest)
				parent->pRightChild = cur;
			else
				parent->pLeftChild = cur;
			cur->pRightChild = dest->pRightChild; //왼쪽에서 올라가는 상황, 오른쪽 자식이 존재했었을 수 있음
			free(dest);
		}
	}
	// 3. 오른쪽 자식 노드가 존재한다면
	else
	{
		cur = dest->pRightChild; //오른쪽으로 가서 가장 작은 값을 가져와야함
		while (cur->pLeftChild) //오른쪽 서브트리의 가장 마지막 왼쪽 자식이 cur가 되도록
		{
			parent = cur;
			cur = cur->pLeftChild;
		}
		if (cur != dest->pRightChild) //왼쪽이 있었다.
		{
			if (cur->pRightChild)
				parent->pLeftChild = cur->pRightChild;
			else
				parent->pLeftChild = NULL;
			dest->key = cur->key;
			free(cur);
		}
		else //왼쪽이 없었다 내가 올라가야 한다.
		{ //cur == dest->pRightChild
			if (parent->pLeftChild == dest)
				parent->pLeftChild = cur;
			else
				parent->pRightChild = cur;
			cur->pLeftChild = dest->pLeftChild;
			free(dest);
		}
	}
	return (TRUE);
}

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key)
{
	if (!pBinSearchTree)
	{
		printf("[Search(Recursive) Fail]: BST does not exist!\n");
		return (NULL);
	}
	
	return (searchInternalRecursiveBST(pBinSearchTree->pRootNode, key));
}

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{
	if (!pTreeNode)
	{
		printf("[Search(Recursive) Fail]: The key does not exist.\n");
		return (NULL);
	}
	if (pTreeNode->key == key)
		return (pTreeNode);
	else if (pTreeNode->key < key)
		return (searchInternalRecursiveBST(pTreeNode->pRightChild, key));
	else if (pTreeNode->key > key)
		return (searchInternalRecursiveBST(pTreeNode->pLeftChild, key));
}

BinSearchTreeNode *searchParentBST(BinSearchTree *pBinSearchTree, int key)
{
	BinSearchTreeNode *cur;
	BinSearchTreeNode *pre;
	
	if (!pBinSearchTree)
	{
		printf("[SearchParent(Iteration) Fail]: BST does not exist!\n");
		return (NULL);
	}
	cur = pBinSearchTree->pRootNode;
	while (cur)
	{
		if (cur->key == key)
			return (pre);
		else
		{
			pre = cur;
			if (cur->key < key)
				cur = cur->pRightChild;
			else
				cur = cur->pLeftChild;
		}
	}
	printf("[SearchParent(Iteration) Fail]: The key does not exist.\n");
	return (NULL);
}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key) //iteration
{
	BinSearchTreeNode *cur;
	
	if (!pBinSearchTree)
	{
		printf("[Search(Iteration) Fail]: BST does not exist!\n");
		return (NULL);
	}
	cur = pBinSearchTree->pRootNode;
	while (cur)
	{
		if (cur->key == key)
			return (cur);
		else if (cur->key < key)
			cur = cur->pRightChild;
		else
			cur = cur->pLeftChild;
	}
	printf("[Search(Iteration) Fail]: The key does not exist.\n");
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