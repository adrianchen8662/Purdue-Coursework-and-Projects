
/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. chen3124@purdue.edu
 *
 *  Homework #: 05
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have I provided access to my code
 *  to another. The effort I am submitting is my own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30AM, SC189
 *
 *  Program Description: Calculates the time needed to calculate a series of instructions
 *
 ***************************************************************************/

#include <stdio.h>
#include <math.h>

long long int getInput();
int splitter(long long int input);
void output(int total);

int main()
{
  //variable declaration
  int total = 0; //total time needed for calculating
  long long int input = 0; //input integer that represents the instruction

  //execution statements
  input = getInput();

  total = splitter(input);

  output(total);

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: long long int
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: gets the inputted int that represents the instruction
*
***************************************************************************/

long long int getInput()
{
  //variable delcaration
  long long int input; //stores the input for instructions

  //execution statements
  printf("Enter instruction to process -> ");
  scanf("%lld", &input);
  return input;
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function: splitter
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. long long int input - The int that represents the instruction
 *
 *  Function Description: Splits the long long int and finds the processing time needed
 *
 ***************************************************************************/

int splitter (long long int input)
{
  //variable declaration
  int x = 0; //x variable in the two-digit code
  int y = 0; //y variable in the two-digit code
  int total = 0; //total processing time
  int lastdatatype = 0; //the last data type the for loop used
  int length = 0; //the position where the splitter is tracking
  
  //execution statements
  if (input == 0)
  {
    total++;
  }
  for(length = 0;  length <= (1 + log10((double)input)) - 1; length += 2)
  {
    x = input / (int)(pow(10,length + 1)) % 10;
    y = input / (int)(pow(10,length)) % 10;
    switch (x)
    {
      case 1:
        total += 4;
        lastdatatype = 4;
        break;
      case 2:
        total += 5;
        lastdatatype = 5;
        break;
      case 3:
        total += 7;
        lastdatatype = 7;
        break;
      default:
        if (lastdatatype == 0 || y == 0)
        {
          total++;
        }
        else
        {
          total += lastdatatype;
        }
        break;
    }
    if (lastdatatype != 0)
    {
      switch (y)
      {
        case 1:
          total += 1;
          break;
        case 2:
          total += 2;
          break;
        case 3:
          total += 4;
          break;
        case 4:
          total += 6;
          break;
        case 5:
          total += 9;
          break;
      }
    }
  }
  return total;
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function: output
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int total - the total processing time needed
 *
 *  Function Description: Prints the total time needed for the instructions
 *
 ***************************************************************************/

void output(int total)
{
  //variable declaration

  //execution statements
  printf("Total time to process instructions = %d", total);
}
