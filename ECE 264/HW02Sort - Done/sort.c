// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // This is the syntax to read or write an array element:
  // int x = arr[4];
  // read the value of arr[4] and store it in x
  // arr[4] = 5;
  // stores 5 in the element arr[4]
  // Please remember that indexes start from 0.

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
  
  int ind1; // First loop value
  int ind2; // Second loop value, index of the smallest element
  int x; // The index to switch
  int swap; // Temporary value for swap

  for (ind1 = 0; ind1 < (size - 1); ind1++)
  {
    x = ind1;
    for (ind2 = ind1 + 1; ind2 < size; ind2++)
    {
      if(arr[ind2] < arr[x])
      {
        x = ind2;
      }
    }
    
    swap = arr[x];
    arr[x] = arr[ind1];
    arr[ind1] = swap;

  }
}
#endif
