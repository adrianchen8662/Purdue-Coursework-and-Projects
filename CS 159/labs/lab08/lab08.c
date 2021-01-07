
/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. chen3124@purdue.edu
 *  2. joshi99@purdue.edu
 *  3. charte277@purdue.edu
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
 *  Program Description: Plays poker
 *
 ***************************************************************************/
//Preprocessor commands
#include <stdio.h>
#include <stdlib.h> //Contains rand() and srand()

void getSeed(); //Gets the seed inputted by the user
void cardDraw(int *value, int *suit, int *acecounter, int *face); //Draws a random cart determined by the seed
void cardCalculation(int *value, int *suit, int *total, int *acecounter); //Calculates info on card
void gameRunner(int *value, int *suit, int *acecounter, int *playertotal, int *dealertotal); //runs the game
void getCardName(int face, int suit); //Prints the name of the card
void whoWonPlayer(int playertotal); //checks if the player won after player phase
void whoWonFinal(int playertotla, int dealertotal); //checks who won after dealer phase

int main()
{
  //variable declaration
  int playertotal = 0; //player's score
  int dealertotal = 0; //dealer's score
  int value = 0; //value of the card
  int suit = 0; //suit of the card
  int acecounter = 0; //how many aces

  //execution statements
  getSeed(); //gets the seed for rand()

  gameRunner(&value, &suit, &acecounter, &playertotal, &dealertotal); //runs the game

  return (0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getSeed
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: Gets the seed and sets it for future rand() functions
*
***************************************************************************/

void getSeed()
{
  //variable declaration
  int seed; //gets the seed from user

  //execution statements
  printf("Enter the seed value -> ");
  scanf("%d", &seed);

  srand(seed);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: cardDraw
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int *value - value of the card
*  2. int *suit - suit of the card
*  3. int *acecounter - how many aces
*  4. int *face - face of the card
*
*  Function Description: Gets a randomized suit, face and value and increments acecounter
*
***************************************************************************/

void cardDraw(int *value, int *suit, int *acecounter, int *face)
{
  //variable declaration
  int new; //stores rand from 1 to 52

  //execution statements
  new = rand() % 52 + 1;
  *suit = new / 13;
  *face = new % 13;
  if (new == 13)
  {
    *suit = *suit - 1;
  }
  else if (new == 26)
  {
    *suit = *suit - 1;
  }
  else if (new == 39)
  {
    *suit = *suit - 1;
  }
  else if (new == 52)
  {
    *suit = *suit - 1;
  }
  if (new % 13 > 10 || new % 13 == 0)
  {
    *value = 10;
  }
  else
  {
	*value = new % 13;
  }
  if (*value == 1)
  {
	  *acecounter = *acecounter + 1;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: cardCalculation
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int *value - value of the card
*  2. int *suit - suit of the card
*  3. int *total - the current score
*  4. int *acecounter - how many aces
*
*  Function Description: calculates the value, suit and adds it to total, incrementing the acecounter if there is an ace
*
***************************************************************************/

void cardCalculation(int *value, int *suit, int *total, int *acecounter)
{
  //execution statements
  if (*value == 1)
  {
    if (*acecounter >= 1 && (*total + 11) >= 21)
	{
      *total += 1;
	}
	else
	{
	  *total += 11;
	}
  }
  else
  {
	*total += *value;
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: gameRunner
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int *value - value of the card
*  2. int *suit - suit of the card
*  3. int *acecounter - how many aces
*  4. int *playertotal - player score
*  5. int *dealertotal - dealer score
*
*  Function Description: Gets the seed and sets it for future rand() functions
*
***************************************************************************/

void gameRunner(int *value, int *suit, int *acecounter, int *playertotal, int *dealertotal)
{
  //variable declaration
  int counter = 1; //cards drawn
  int face = 0; //value of face

  //execution statements
  while (*playertotal <= 16) //while loop until player hits over the limit
  {
	cardDraw(value, suit, acecounter, &face);
    printf("Card #%d: ", counter);
	counter++;
    getCardName(face, *suit);
	cardCalculation(value, suit, playertotal, acecounter);
	printf("\n");
  }
  printf("Player's score = %d\n\n", *playertotal);
  whoWonPlayer(*playertotal);

  if (*playertotal <= 21)
  {
	  counter = 1;

	  while (*dealertotal <= 16) //while loop until dealer hits over the limit
	  {
	    cardDraw(value, suit, acecounter, &face);
	  	printf("Card #%d: ", counter);
	  	counter++;
	  	getCardName(face, *suit);
	  	cardCalculation(value, suit, dealertotal, acecounter);
	  	printf("\n");
	  }
	  printf("Dealer's score = %d", *dealertotal);

	  whoWonFinal(*playertotal, *dealertotal);
  }

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getCardName
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*  1. int face - face of the card
*  2. int suit - suit of the card
*
*  Function Description: gets the name of the card
*
***************************************************************************/

void getCardName(int face, int suit)
{
  //execution statements
  switch(face)
  {
    case 1:
      printf("Ace");
      break;
    case 11:
      printf("Jack");
      break;
    case 12:
      printf("Queen");
      break;
    case 0:
      printf("King");
      break;
    default:
      printf("%d", face);
      break;
  }
  printf(" of ");
  switch (suit)
  {
    case 1:
      printf("Diamonds");
      break;
    case 2:
      printf("Hearts");
      break;
    case 3:
      printf("Spades");
      break;
    case 0:
      printf("Clubs");
      break;
   }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: whoWonPlayer
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int playertotal - how many points the player has
*
*  Function Description: who won after player draws
*
***************************************************************************/

void whoWonPlayer(int playertotal)
{
  //execution statements
  if (playertotal > 21)
  {
	  printf("\n\nDealer wins!");
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: whoWonFinal
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int playertotal - how many points the player has
*  2. int dealertotal - how many points the dealer has
*
*  Function Description: who wins after dealer draws
*
***************************************************************************/

void whoWonFinal(int playertotal, int dealertotal)
{
  //execution statements
  if (dealertotal > 21)
  {
	  printf("\n\nDealer busts!");
  }
  else if (dealertotal >= playertotal)
  {
	  printf("\n\nDealer wins!");
  }
  else
  {
	  printf("\n\nDealer loses!");
  }
}
