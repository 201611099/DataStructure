#include "./bintree.h"
#include "./traversal/traversal.h"

int main(void)
{
  BinTreeNode *root = makeBinTreeNode('A');
  BinTreeNode *nb = makeBinTreeNode('B');
  BinTreeNode *nc = makeBinTreeNode('C');
  BinTreeNode *nd = makeBinTreeNode('D');
  BinTreeNode *ne = makeBinTreeNode('E');
  BinTreeNode *nf = makeBinTreeNode('F');
  BinTreeNode *ng = makeBinTreeNode('G');
  BinTreeNode *nh = makeBinTreeNode('H');
  BinTreeNode *ni = makeBinTreeNode('I');
  BinTreeNode *nj = makeBinTreeNode('J');
  BinTreeNode *nk = makeBinTreeNode('K');
  BinTreeNode *nl = makeBinTreeNode('L');
  BinTreeNode *nm = makeBinTreeNode('M');
  
  BinTree *tree = makeBinTree(root);
  printf("getRootNodeBT1 %c\n", getRootNodeBT(tree)->data);

  insertLeftChildNodeBT(root, nb);
  printf("getRootNodeBT2 %c %c\n", getRootNodeBT(tree)->data, tree->pRootNode->data);

  printf("root %c\n", tree->pRootNode->data);

  insertRightChildNodeBT(root, nc);
  printf("getRootNodeBT3 %c\n", getRootNodeBT(tree)->data);
  insertLeftChildNodeBT(nb, nd);
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertRightChildNodeBT(nb, ne);
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertLeftChildNodeBT(nd, nh);
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertRightChildNodeBT(nd, ni);
  
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertLeftChildNodeBT(ne, nj);
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertLeftChildNodeBT(nc, nf);
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertRightChildNodeBT(nc, ng);
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertRightChildNodeBT(nf, nk);
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertLeftChildNodeBT(ng, nl);
  printf("getRootNodeBT %c\n", getRootNodeBT(tree)->data);
  insertRightChildNodeBT(ng, nm);
  
  printf("getRootNodeBT %c %c\n", getRootNodeBT(tree)->data, tree->pRootNode->data);
  printf("getLeftChildNodeBT(root) %c, %c, %c\n", root->pLeftChild->data, root->data, root->pRightChild->data);
  printf("getRightChildNodeBT(root) %c\n", getRightChildNodeBT(root)->data);

//traversal
  
  Preorder_Traversal(tree->pRootNode);
  printf("\n");
  Inorder_Traversal(tree->pRootNode);
  printf("\n");
  Postorder_Traversal(tree->pRootNode);
  printf("\n");
  Level_Traversal(tree->pRootNode);
  printf("\n");

  deleteBinTree(tree);
  return (0);
}