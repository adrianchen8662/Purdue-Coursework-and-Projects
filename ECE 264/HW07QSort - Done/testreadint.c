//tests reading int
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *fp;
  int loop;
  int number;
  int total;
  int intArr[20];

  fp = fopen("test.txt","r");
  if(fp == NULL)
  {
    printf("Nope\n");
  }
  else
  {
    while(!feof(fp))
    {
      if(fscanf(fp,"%d",&number)!=EOF)
      {
        intArr[loop] = number;
        total++;
        loop++;
      }
      ftell(fp);
    }
  }
  for(loop = 0; loop < 10; loop++)
  {
    printf("%d\n",intArr[loop]);
  }
  fclose(fp);
}
