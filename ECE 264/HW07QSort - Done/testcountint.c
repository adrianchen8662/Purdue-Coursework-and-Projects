#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *fp;
  int counter = 0;
  char c;
  fp = fopen("test.txt","r");
  if(fp == NULL)
  {
    printf("Nope\n");
  }
  else
  {
    for(c = getc(fp); c!=EOF;c=getc(fp))
    {
      if(c == '\n')
      {
        counter++;
      }
    }
  }
  fclose(fp);
  printf("Counter = %d\n",counter);
}
