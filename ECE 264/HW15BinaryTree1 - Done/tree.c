// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void deleteTreeNode(TreeNode *tr);
static void preOrderNode(TreeNode *tn, FILE * fptr);
TreeNode * newNode(int value);
int search(int* arr, int strt, int end, int value);
TreeNode* buildUtil(int* inArray, int* postArray, int inStrt, int inEnd, int *pIndex);

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
TreeNode* newNode(int value)
{
  TreeNode* node = NULL;
  node = (TreeNode*)malloc(sizeof(TreeNode));
  node->value = value;
  node->left = node->right = NULL;
  return (node);
}

int search(int* arr, int strt, int end, int value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
    {
      break;
    }
  }
  return i;
}

TreeNode* buildUtil(int* inArray, int* postArray, int inStrt, int inEnd, int* pIndex)
{
  if(inStrt > inEnd)
  {
    return NULL;
  }
  
  TreeNode* node = NULL;
  node = newNode(postArray[*pIndex]);
  (*pIndex)--;

  if(inStrt == inEnd)
  {
    return node;
  }

  int iIndex = search(inArray, inStrt, inEnd, node->value);

  node->right = buildUtil(inArray, postArray, iIndex + 1, inEnd, pIndex);
  node->left = buildUtil(inArray, postArray, inStrt, iIndex - 1, pIndex);

  return node;
}

Tree* buildTree(int* inArray, int* postArray, int inSize)
{
  int pIndex = inSize - 1;
  TreeNode* firstNode = buildUtil(inArray, postArray, 0, inSize - 1, &pIndex);
  Tree* Thing = NULL;
  Thing = (Tree*)malloc(sizeof(Tree));
  Thing->root = firstNode;
  return Thing;
}
#endif
