
/***************************************************************************
 *
 *  Programmers and Purdue Email Addresses:
 *  1. chen3124@purdue.edu
 *  2. joshi99@purdue.edu
 *  3. charte277@purdue.edu (delete line if no third partner)
 *
 *  Lab #: 09
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30AM, SC 189
 *
 *  Program Description: Finds the target data int in an inputted data int in sequential order. In the absence of the target data, finds the next int that does in sequential order.
 *
 ***************************************************************************/

//preprocessor commands
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//function declaration
void inputData(long long int *inputdata, long long int *targetdata);
int findTarget(long long int inputdata, long long int targetdata);
long long int searchTarget(long long int inputdata, long long int targetdata);

int main()
{
  //variable declaration
  long long int inputdata; //stores the input data
  long long int targetdata; //stores the data to be found
  int targetfound; //the int that findTarget returns, could be 0, could be partial targetdata, could be targetdata
  long long int nextint; //the next int that contains targetdata

  //execution statements
  //prompts user for inputdata and targetdata
  inputData(&inputdata, &targetdata);

  //loops until inputdata length is longer than targetdata
  //floor(log10(abs(INTEGER_VARIABLE))) + 1 finds the length of an int
  while ((floor(log10(abs(inputdata))) + 1) < (floor(log10(abs(targetdata))) + 1))
  {
    printf("Error! The number of digits in target cannot exceed those in the data!\n");
    inputData(&inputdata, &targetdata);
  }

 	targetfound = findTarget(inputdata, targetdata);
  if (targetfound == targetdata)
  {
    printf("Target: %lld found", targetdata);
  }

  else
  {
    nextint = searchTarget(inputdata, targetdata);
    printf("Next value to contain target: %lld", nextint);
  }

  return(0);
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
*  1. int *inputdata - inputted data
*  2. int *targetdata - target data to find in inputdata
*
*  Function Description: gets the inputted data and a target data
*
***************************************************************************/

void inputData(long long int *inputdata, long long int *targetdata)
{
  //execution statments
  printf("Enter data to search -> ");
  scanf("%lld", inputdata);
  printf("Enter target to locate -> ");
  scanf("%lld", targetdata);
  printf("\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findTarget
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*  1. long long int inputdata - inputted data
*  2. long long int targetdata - target data to find in inputdata
*
*  Function Description: Finds the targetdata in inputdata
*
***************************************************************************/

int findTarget(long long int inputdata, long long int targetdata)
{
  //variable declaration
  int targettemp; //temporary target data
  int inputtemp; //temporary input data
  int targetcounter; //for loop counter for target
  int inputcounter; //for loop counter for input
  int targetfound = 0; //target data counter

  //execution statements
  for (targetcounter = (floor(log10(abs(targetdata))) + 1); targetcounter > 0; targetcounter--)
  {
	targettemp = (targetdata / (int)pow(10,targetcounter - 1)) % 10;
    for (inputcounter = (floor(log10(abs(inputdata))) + 1); inputcounter > 0; inputcounter--)
    {
      inputtemp = (inputdata / (int)pow(10,inputcounter - 1)) % 10;
      if (targettemp == inputtemp)
      {
        targetfound *= 10;
        targetfound += targettemp;
        inputdata = (inputdata % (int)pow(10,inputcounter - 1));
      }
    }
  }

  return(targetfound);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: searchTarget
*
*  Function Return Type: long long int
*
*  Parameters (list data type, name, and comment one per line):
*  1. long long int inputdata - inputted data
*  2. long long int targetdata - target data to find in inputdata
*
*  Function Description: Find the next int that contains targetdata in a specific order
*
***************************************************************************/

long long int searchTarget(long long int inputdata, long long int targetdata)
{
  //variable declaration
  int targettemp; //current data found by findTarget

  //execution statements
  while (targettemp != targetdata)
  {
    inputdata++;
    targettemp = findTarget(inputdata, targetdata);
  }

  return(inputdata);
}
