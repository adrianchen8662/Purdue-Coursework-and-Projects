#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct HuffNode
{
  char data;
  struct HuffNode *left;
  struct HuffNode *right;
}HuffNode;

typedef struct HuffRoot
{
  HuffNode *root;
}HuffRoot;

int countChar(char* filename);
int inputChar(char* intInput, char* filename);
HuffRoot buildHuff();
