// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
  FILE *fp;
  int counter = 0;
  char c;
  fp = fopen(filename,"r");
  if(fp == NULL)
  {
    return -1;
  }
  for(c=getc(fp); c!=EOF; c=getc(fp))
  {
    if(c == '\n')
    {
      counter++;
    }
  }
  fclose(fp);
  return(counter);
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  FILE *fp;
  int loop = 0;
  int number;
    
  fp = fopen(filename,"r");
  if(fp == NULL)
  {
    return false;
  }
  while(!feof(fp))
  {
    if(fscanf(fp,"%d",&number)!=EOF)
    {
      intArr[loop] = number;
      loop++;
    }
    ftell(fp);
  }
  if(loop != size)
  {
    return false;
  } 
  fclose(fp);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  /*
  if(p1 < p2)
  {
    return -1;
  }
  else if(p1 > p2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  */
  return(*(int*)p1-*(int*)p2);
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  // 
  // fclose and return true
  FILE *fp;
  int loop;

  fp = fopen(filename,"w");
  if(fp == NULL)
  {
    return false;
  }
  for(loop = 0; loop < size; loop++)
  {
    fprintf(fp,"%d\n",intArr[loop]);
  }
  fclose(fp);
  return true;
}
#endif
