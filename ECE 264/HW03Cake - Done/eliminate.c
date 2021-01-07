// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an array of n elements
  int * arr = malloc(sizeof(* arr) * n);
  
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  
  // initialize all elements
  int arraysize = n;
  int counter = k;
  int itemloop;
  int final;
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  while (arraysize > 1)
  {
    for (itemloop = 0; itemloop < n; itemloop++)
    {
      if (arr[itemloop] != -1 && counter == 1)
      {
        printf("%d\n", itemloop);
        counter = k;
        arr[itemloop] = -1;
        arraysize--;
      }
      else
      {
        if (arr[itemloop] != -1)
        {
          counter--;
        }
      }
    }
  }

  // print the last one
  for(itemloop = 0; itemloop < n; itemloop++)
  {
    if (arr[itemloop] != -1)
    {
      final = itemloop;
    }
  }
  printf("%d\n", final);

  // release the memory of the array
  free (arr);
}
#endif
