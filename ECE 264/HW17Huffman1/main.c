#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw17.h"

static bool readInput(const char * filename, int * * array, int * size)
{
  FILE * fptr = fopen(filename,"r");
  if(fptr == NULL)
  {
    return false;
  }
  int numint = 0;
  int value;
  while (fscanf(fptr, "%d", &value) ==1)
  {
    numint++;
  }
  if(numint == 0)
  {
    return false;
  }
  *size = numint;
  int* arr = malloc(sizeof(int)*numint);
  fseek(fptr,0,SEEK_SET);
  int ind = 0;
  while(ind < numint)
  {
    if(fscanf(fptr, "%d", &arr[ind]) != 1)
    {
      fprintf(stderr, "SOMETHING WRONG\n");
      free(arr);
      *size = 0;
      return false;
    }
    ind++;
  }
  fclose(fptr);
  *array = arr;
  return true;
}
int main(int argc, char ** argv)
{
  int *huffArray;
  int inSize;
  if(argc != 1)
  {
    return EXIT_FAILURE;
  }
  bool rtv = readArray(argv[1], &huffArray, &inSize);
  if(rtv == false)
  {
    return EXIT_FAILURE;
  }
  HuffRoot* root = NULL;
  root = buildHuff();
  freeHuff(root);
  free(huffArray);
}
