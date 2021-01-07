
/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. chen3124@purdue.edu
 *  2. joshi99@purdue.edu
 *
 *  Lab #: 08
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have I provided access to my code
 *  to another. The effort I am submitting is my own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30AM, SC189
 *
 *  Program Description: Creates a
 *
 ***************************************************************************/

#include <stdio.h>
#include <math.h>

int inputs();
void secondCall(int, int, int*, int*, int*, int*);
void whichCard(int)
void newCard(int, int*, int*, int*);
int cardPrint(int);
void suitePrint(int);

int main
{
    //Local Declarations
    int seedVal;
    int numCard;
    int suiteCard;
    int valueCard;
    int playerSum;
    int dealerSum;

    int cardCount = 0;
    int aceCount = 0;

    //Function Calls
     seedVal = inputs();

     secondCall(seedVal, ++cardCount, &numCard, &suiteCard, &valueCard, &aceCount, playerSum);
     printf("\nPlayer's Score: %d", playerSum);

     cardCount = 0;
     aceCount = 0;
     secondCall(seedVal, ++cardCount, &numCard, &suiteCard, &valueCard, &aceCount, dealerSum);
     printf("\nDealer's: %d", dealerSum);

     playerSum < dealerSum ? printf("Dealer Wins!") : printf("Dealer Loses!");



}

int inputs()
{
  //Local Declarations
  int seedInput;

  //Executable Statements
  printf("\nEnter the seed value -> ");
  scanf("%d", seedInput);

  srand(seedInput);

  return(seedInput);
}

void secondCall(int seedIn, int calcCard, int *calcNum, int *calcSuite, int *calcValue, int *aces, int *currentSum)
{
    //Local Declarations
    int aceNum;
    int currentSum = 0;

    //Function Calls
    while (currentSum < 16)
    {
        newCard(seedIn, &calcNum, &calcSuite, &calcValue);
        whichCard(calcCard);
        aceNum = cardPrint(&calcNum);
        suitePrint(&calcSuite)
        *currentSum += &calcValue;
    }

    return;
}

void whichCard(int count)
{
    printf("\nCard #%d: ", count);
    return;
}

void newCard(int seedInput, int *num, int *suite, int *value)
{
  new = rand() % 52 + 1;
  *num = new % 13;
  *suite = new / 14
  *value = num < 10 ? num : 10;

  return;
}

int cardPrint(int num)
{
    //Local Declarations
  int aces;

  //Executable Statements
  if (num == 1)
  {
    printf("Ace");
    aces = 1;
  }
  else if (num <= 10 && num != 1)
  {
    printf("%lf", num);
  }
  else if (num == 11)
  {
    printf("Jack");
  }
  else if (num == 12)
  {
    printf("Queen");
  }
  else
  {
    printf("King");
  }

  return(aces);
}

void suitePrint(int suite)
{
    printf(" of ");

    switch(suite)
    {
        case 1: printf("Clubs");
                break;
        case 2: printf("Diamonds");
                break;
        case 3: printf("Hearts");
                break;
        default: printf("Spades");
    }

    return;
}
