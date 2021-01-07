
/***************************************************************************
 *
 *  Programmers and Purdue Email Addresses:
 *  1. chen3124@purdue.edu
 *  2. joshi99@purdue.edu
 *  3. carte277@purdue.edu
 *
 *  Lab #: 10
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30AM, SC 189
 *
 *  Program Description: Finds the prime numbers starting from a number, and prints outputs based on the 10th integer in the array
 *
 ***************************************************************************/

//preprocessor statements
#include <stdio.h>
#include <math.h>

//function initialization
int valueInput ();
void primeArray (int primearray[10], int valueinput);
void findOutput (int primearray[10]);

int main ()
{
  //variable declaration
  int inputvalue; //inputted value
  int primearray[10]; //array of prime numbers

	//execution statement
  inputvalue = valueInput();
	primeArray (primearray, inputvalue);
  findOutput (primearray);

  return (0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: valueInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: gets the input value to start finding prime numbers
*
***************************************************************************/

int valueInput ()
{
  //variable declaration
  int inputvalue; //inputted value

  //execution statements
  printf ("Enter starting value -> ");
  scanf ("%d", &inputvalue);

  return (inputvalue);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: primeArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int primearray[] - array that holds the prime numbers
*  2. int inputvalue - inputted value
*
*  Function Description: Finds the next 10 primes after the inputted value and stores it into an array
*
***************************************************************************/

void primeArray (int primearray[], int inputvalue)
{
  //variable declaration
  int primecounter; //counter for the prime number finding loop
  int ifprime = 0; //int that stores if the number is a prime or not
  int nextnumber = inputvalue; //next number in the loop to be tested for prime
  int arraycounter = 0; //counter for the while loop to fill the array

  //execution statements
  while (arraycounter < 10)
  {
    ifprime = 0;

    for (primecounter = 2; primecounter <= nextnumber / 2; primecounter++)
    {
      if (nextnumber % primecounter == 0)
      {
        ifprime = 1;
      }
    }
    if (ifprime == 0)
  	{
    	primearray[arraycounter] = nextnumber;
    	arraycounter++;
  	}
    nextnumber++;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int primearray[] - array that holds the prime numbers
*
*  Function Description: Finds the output from the 10th prime number and prints it
*
***************************************************************************/

void findOutput (int primearray[])
{
  //variable declaration
  int whichoutput = primearray[9]; //the 10th prime number that determines what to print
  int i; //counter for the loop that goes through the 10th prime number
  int x; //holds the ints split from the 10th prime number

  //execution statements
  printf ("Requested Primes: ");
  for (i = 0; i < (1 + log10((double)whichoutput)) - 1; i++)
  {
    x = whichoutput / (int)(pow(10,i)) % 10;;
    printf ("%d ", primearray[x]);
  }
  printf ("\n");
}
