// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void deleteTreeNode(TreeNode *tr);
TreeNode * newNode(int value);
int search(int* arr, int strt, int end, int value);
TreeNode* buildUtil(int* inArray, int* postArray, int inStrt, int inEnd, int *pIndex);
int hasPath (TreeNode* tr, int path[], int val, int counter);

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
  TreeNode* firstNode = NULL;
  Tree* Thing = NULL;
  firstNode = buildUtil(inArray, postArray, 0, inSize - 1, &pIndex);
  Thing = (Tree*)malloc(sizeof(Tree));
  Thing->root = firstNode;
  return Thing;
}
#endif

#ifdef TEST_PRINTPATH
int hasPath(TreeNode *tr, int path[], int val, int counter)
{
  if(tr == NULL)
  {
    return 1;
  }
  path[counter-1] = (tr->value);
  counter++;
  if(hasPath(tr->left, path, val, counter) || hasPath(tr->right, path, val,counter))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void printPath(Tree* tr, int val)
{
  int x = 0;
  int path[20] = {0};
  int counter = 1;
  TreeNode* newNode = NULL;
  newNode = tr->root;
  hasPath(newNode, path, val, counter);
  for(x = 19; x >= 0; x--)
  {
    if(path[x]!= 0)
    {
      printf("%d\n",path[x]);
    }
  }
}
#endif
