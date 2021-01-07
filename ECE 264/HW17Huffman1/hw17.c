#include <stdio.h>
#include <stdlib.h>

void deleteHuffNode(HuffNode * huff)
{
  if(huff == NULL)
  {
    return;
  }
  deleteHuffNode(huff->left);
  deleteHuffNode(huff->right);
  free(huff);
}

void freeTree(HuffRoot * huff)
{
  if(huff == NULL)
  {
    return;
  }
  deleteHuffNode(huff ->root);
  free(huff);
}

int hasPath(HuffNode *huff, int path[], int val, int counter)
{
  if(huff == NULL)
  {
    return 1;
  }
  int x = hasPath(tr->left, path, val, counter);
  int y = hasPath(tr->right,path,val,counter);
  if(x == 1)
  {
    path[counter-1] = 0;
  }
  if(y == 1)
  {
    path[counter-1] = 1;
  }
  counter++;
  if(x || y)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void printPath(HuffRoot *root, int val)
{
  int x = 0;
  int path[20] = {0};
  int counter = 1;
  HuffNode* newNode = {0};
  newNode = root->root;
  hasPath(newNode, path, val, counter);
  for(x = 19, x >= 0; x--)
  {
    if(path[x] != 0)
    {
      printf("%d\n", path[x]);
    }
  }
}
