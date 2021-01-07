/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. chen3124@purdue.edu
 *
 *  Homework #: 07
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have I provided access to my code
 *  to another. The effort I am submitting is my own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30AM, SC189
 *
 *  Program Description: Creates a set array and random array and compares each to find like numbers
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define SIZEINPUT 30
#define SIZERANDOM 1000

void arrayInput(int arr[], int* seedvalue);
void addRandom(int arr[], int seedvalue);
void findValues(int arr[], int arrrandom[]);

int main()
{
  //variable declaration
  int arrinput[SIZEINPUT]; //random array of size SIZEINPUT
  int arrrandom[SIZERANDOM]; //random array of size SIZERANDOM
  int seedvalue; //random seed value

  //execution statements
  arrayInput(arrinput, &seedvalue);
  addRandom(arrrandom, seedvalue);
  findValues(arrinput, arrrandom);
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
*  1. int arr[] - array to be sorted
*  2. int* seedvalue - random seed value
*
*  Function Description: inputs ints into array from user
*
***************************************************************************/

void arrayInput(int arr[], int* seedvalue)
{
  //variable declaration
  int i; //loop control variable

  //execution statements
  printf("Enter seed value -> ");
  scanf("%d", seedvalue);

  printf("Enter up to 30 integers or -1 to exit: ");
  for (i = 0; i < SIZEINPUT; i++)
  {
    if (arr[i-1] == -1)
    {
      i = SIZEINPUT;
    }
    else
    {
      scanf("%d", &arr[i]);
    }
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: addRandom
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int arr[] - array to contain random values
*  2. int seedvalue - value of the seed
*
*  Function Description: inputs random ints into array
*
***************************************************************************/

void addRandom(int arr[], int seedvalue)
{
  //variable declaration
  int arraycounter; //loop control

  //execution statements
  srand(seedvalue);
  for(arraycounter = 0; arraycounter < SIZERANDOM; arraycounter++)
  {
    arr[arraycounter] = rand() % 1000 + 1;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int arrinput[] - array of input values
*  2. int arrrandom[] - array of random values
*
*  Function Description: finds the number of similar values and prints it
*
***************************************************************************/

void findValues(int arrinput[], int arrrandom[])
{
  //variable declaration
  int counter = 0; //counter for total values found
  int i; //outer loop control variable
  int j; //inner loop control variable

  //execution statements
  for(i = 0; i < SIZEINPUT; i++)
  {
    for(j = 0; j < SIZERANDOM; j++)
    {
      if(arrinput[i] == arrrandom[j])
      {
        counter++;
        j = SIZERANDOM;
      }
    }
  }

  printf("\nTotal number of values found: %d", counter);
}
