/***************************************************************************
 *
 *  Programmers and Purdue Email Addresses:
 *  1. chen3124@purdue.edu
 *  2. joshi99@purdue.edu
 *  3. carte277@purdue.edu
 *
 *  Lab #: 12
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30AM, SC 189
 *
 *  Program Description: creates an array based on parameters set by the user, sorts it and finds the index and element to print
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputData(int* datasize, int* seedvalue);
void fillArray(int arr[], int datasize, int seedvalue);
void sortArray(int arr[], int datasize);
void printElement(int arr[], int datasize);

int main()
{
  //variable declaration
  int datasize = 0; //size of the array
  int seedvalue = 0; //random seed value
  int* arr; //array pointer

  //execution statments
  inputData(&datasize, &seedvalue);

  arr = (int*) malloc(datasize * sizeof(int)); //sets the array size to data size

  fillArray(arr, datasize, seedvalue);
  sortArray(arr, datasize);

  printElement(arr, datasize);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputData
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int* datasize - size of the array
*  2. int* seedvalue - random array seed
*
*  Function Description: gets inputs from user on size of array and seed value
*
***************************************************************************/

void inputData(int* datasize, int* seedvalue)
{
  //execution statements
  //gets the seed value
  printf("Enter data set size -> ");
  scanf("%d", datasize);
  //checks the datasize for less than 10 and greater than 1000
  while (*datasize < 10 || *datasize > 1000)
  {
    if(*datasize < 10)
    {
      printf("\nError! Minimum data set size is 10. \n\n");
    }
    if(*datasize > 1000)
    {
      printf("\nError! Maximum data set size is 1000. \n\n");
    }
    printf("Enter data set size -> ");
    scanf("%d", datasize);
  }

  //gets the seed value
  printf("Enter seed value -> ");
  scanf("%d", seedvalue);
  //checks the seed value for less than 0
  while (*seedvalue < 0)
  {
    printf("\nError! the seed value must be positive!! \n\n");
    printf("Enter seed value -> ");
    scanf("%d", seedvalue);
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: fillArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int arr[] - array pointer
*  2. int datasize - size of the array
*
*  Function Description: fills the array with random values from 1 to 10000
*
***************************************************************************/

void fillArray(int arr[], int datasize, int seedvalue)
{
  //variable declaration
  int i; //loop control

  //execution statements
  srand(seedvalue);
  for(i = 0; i < datasize; i++)
  {
    arr[i] = rand() % 10000  + 1;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sortArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int arr[] - array pointer
*  2. int datasize - size of the array
*
*  Function Description: sorts the array using bubble sort
*
***************************************************************************/

void sortArray(int arr[], int datasize)
{
  //variable declaration
  int i; //outer loop control
  int j; //inner loop control
  int temp; //temporary storage value;

  //execution statements
  for(i = 0; i < datasize-1; i++)
  {
    for(j = 0; j < datasize-i-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printElement
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int arr[] - array pointer
*  2. int datasize - size of the array
*
*  Function Description: finds the index to print and prints the index and the element
*
***************************************************************************/

void printElement(int arr[], int datasize)
{
  //variable declaration
  int desiredindex; //the index to find

  //execution statements
  desiredindex = arr[datasize - 1] % datasize;

  printf("\nDesired index: %d", desiredindex);
  printf("\nDesired element: %d", arr[desiredindex]);
}
