/***************************************************************************
 *
 *  Programmers and Purdue Email Addresses:
 *  1. chen3124@purdue.edu
 *  2. joshi99@purdue.edu
 *  3. carte277@purdue.edu
 *
 *  Lab #: 11
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30AM, SC 189
 *
 *  Program Description: Generates an 1000-int array, sorts greatest to least, and prints the array places asked
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputValues(int* seedvalue, int* startingvalue, int*endingvalue);
void fillArray(int arr[], int seedvalue);
void sortArray(int arr[]);
void getValues(int startingvalue, int endingvalue, int arr[]);

int main()
{
  //variable declaration
  int seedvalue; //value of the random seed
  int startingvalue; //first array place to print
  int endingvalue; //last array to print
  int arr[1000]; //array size 1000

  //execution statements
  inputValues(&seedvalue, &startingvalue, &endingvalue);

  fillArray(arr, seedvalue);
  sortArray(arr);

  getValues(startingvalue, endingvalue, arr);

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int* seedvalue - value of the random seed
*  2. int* startingvalue - first array place to print
*  3. int* endingvalue - final array place to print
*
*  Function Description: Gets the values to input and to output
*
***************************************************************************/

void inputValues(int* seedvalue, int* startingvalue, int* endingvalue)
{
  //seedvalue input
  printf("Enter seed value -> ");
  scanf("%d", seedvalue);
  //if seedvalue is less than or equal to zero, repeat
  while(*seedvalue <= 0)
  {
    printf("\nError! Positive values only!!\n\n");
    printf("Enter seed value -> ");
    scanf("%d", seedvalue);
  }

  //startingvalue input
  printf("Enter starting range value -> ");
  scanf("%d", startingvalue);
  //if startingvalue is less than zero or greater than or equal to 1000, repeat
  while(*startingvalue < 0 || *startingvalue >= 1000)
  {
    if(*startingvalue < 0)
    {
      printf("\nError! Start value must be non-negative!\n\n");
    }
    else if(*startingvalue >= 1000)
    {
      printf("\nError! Start value must be less than 1000!!\n\n");
    }
    printf("Enter starting value range -> ");
    scanf("%d", startingvalue);
  }

  //endingvalue input
  printf("Enter ending range value -> ");
  scanf("%d", endingvalue);
  //if endingvalue is less than startingvalue or greater than or equal to 1000, repeat
  while(*endingvalue < *startingvalue || *endingvalue >= 1000)
  {
    if(*endingvalue < *startingvalue)
    {
      printf("\nError! Ending value cannot be less than starting value!\n\n");
    }
    else if(*endingvalue >= 1000)
    {
      printf("\nError! Ending value must be less than 1000!!\n\n");
    }
    printf("Enter ending range value -> ");
    scanf("%d", endingvalue);
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
*  1. int arr[] - array of 1000 ints
*  2. int seedvalue - value of the seed
*
*  Function Description: fills the array based on a seed value
*
***************************************************************************/

void fillArray(int arr[], int seedvalue)
{
  //variable declaration
  int arraycounter; //loop control

  //execution statements
  srand(seedvalue);
  for(arraycounter = 0; arraycounter < 1000; arraycounter++)
  {
    arr[arraycounter] = rand() % 1000000 + 1;
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
*  1. int arr[] - array of 1000 random ints
*
*  Function Description: sorts the array from greatest to least
*
***************************************************************************/

void sortArray(int arr[])
{
  //variable declaration
  int size = 1000; //size of the array
  int i; //outer loop control
  int j; //inner loop control
  int temp; //holds the temporary value
  int minimum; //place of the temporary variable

  //execution statements
  //selection sort from greatest to least
  for(i = 0; i < size - 1; i++)
	{
		temp = i;
		for(j = i + 1; j < size; j++)
		{
			if( arr[j] > arr[minimum])
			{
				minimum = j;
			}
		}
		temp = arr[minimum];
		arr[minimum] = arr[i];
		arr[i] = temp;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int startingvalue - first array place to print
*  2. int endingvalue - last array place to print
*  3. int arr[] - array of 1000 ints
*
*  Function Description: gets the values from startingvalue to endingvalue
*
***************************************************************************/

void getValues(int startingvalue, int endingvalue, int arr[])
{
  //variable declaration
  int arraycounter; //counter for arrays

  //execution statements
  printf("Requested values %d - %d: ", startingvalue, endingvalue);
  for(arraycounter = startingvalue; arraycounter <= endingvalue; arraycounter++)
  {
    if(arraycounter == endingvalue)
    {
      printf("%d", arr[arraycounter]);
    }
    else
    {
      printf("%d, ", arr[arraycounter]);
    }
  }
}
