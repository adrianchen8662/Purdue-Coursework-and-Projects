/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. chen3124@purdue.edu
 *
 *  Homework #: 06
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have I provided access to my code
 *  to another. The effort I am submitting is my own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30AM, SC189
 *
 *  Program Description: Take input into an array and find the sum of the products in the array
 *
 ***************************************************************************/

#include <stdio.h>
#define MAX_SIZE 20

void getArray(int arr[], int size);
int productCalculator(int arr[]);

int main()
{
  //variable declaration
  int arr[MAX_SIZE]; //array size 20
  int total; //total product from array

  //execution statements
  getArray(arr, MAX_SIZE);
  total = productCalculator(arr);
  printf("Final product: %d", total);

  return (0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int arr[] = 20-integer array
*  2. int size = how big the array is
*
*  Function Description: Gets input into the array
*
***************************************************************************/

void getArray(int arr[], int size)
{
  //variable declaration
  int i; //loop for input into array

  //execution statements
  printf("Enter 20 integers -> ");
  for (i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: productCalculator
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*  1. int arr[] - 20-integer array
*
*  Function Description: Finds the sum of the products from an array
*
***************************************************************************/

int productCalculator(int arr[])
{
  //variable declaration
  int i; //loop variable for product calculation
  int atemp; //temporary variable for the value at the location i
  int btemp; //temporary variable for the value at the location atemp
  int total = 0; //running total of the products of atemp and btemp

  //execution statements
  for(i = 0; i < 20; i++)
  {
    if(arr[i] < 20 && i < 20 && arr[i] >= 0 && i >= 0)
    {
      atemp = arr[i];
      btemp = arr[atemp];
      total = total + (atemp * btemp);
    }
  }

  return(total);
}
