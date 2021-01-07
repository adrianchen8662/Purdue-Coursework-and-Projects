// ***
// *** DO NOT modify this file
// ***

#ifndef TREE_H
#define TREE_H

//binary tree node
typedef struct tnode
{
  int value; //data of node
  struct tnode * left; //pointer to left child
  struct tnode * right; //pointer to right child
} TreeNode;

//
typedef struct trnode
{
  TreeNode * root;
} Tree;

void freeTree(Tree * tr);
void preOrder(Tree * tr, char * filename);
Tree* buildTree(int* inArray, int* postArray, int inSize);


#endif
