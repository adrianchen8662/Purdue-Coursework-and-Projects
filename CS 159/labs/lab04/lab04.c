
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. login1@purdue.edu
*  2. login2@purdue.edu
*  3. login3@purdue.edu (delete line if no third partner)
*
*  Lab #:
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab:
*
*  Program Description:
*
***************************************************************************/

#include<stdio.h>
#include<math.h>
#define Coulomb (8.99 * pow(10,9))

double input_charge(double);
double input_coordinate(double, char);
double magnitude(double, double, double);
double force_angle(double, double);
void output(double, double);

int main()
{
  double inputNumber = 1;
  char coordinateName = 'Y';
  double charge1 = 0;
  double charge2 = 0;
  double charge3 = 0;
  double yCoord = 0;
  double xCoord = 0;
  double forcex = 0;
  double forcey = 0;
  double resultantForce = 0;
  double angleForce = 0;


  charge1 = input_charge(inputNumber);
  inputNumber++;
  charge2 = input_charge(inputNumber);
  inputNumber++;
  charge3 = input_charge(inputNumber);
  inputNumber = 2;
  yCoord = input_coordinate(inputNumber, coordinateName);
  inputNumber++;
  coordinateName--;
  xCoord = input_coordinate(inputNumber, coordinateName);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

double input_charge(double inputNumber)
{
  double input = 0;
  printf("Enter charge [micro-Coulomb] of point #%d -> ",&inputNumber);
  scanf("%d", input);
  return input;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

double input_coordinate(double inputNumber, char coordinateName)
{
  double input = 0;
  printf("Enter %c coordinate[cm of point #%ls -> ",&coordinateName, &inputNumber);
  scanf("%ls", input);
  return input;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
   Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

double 
