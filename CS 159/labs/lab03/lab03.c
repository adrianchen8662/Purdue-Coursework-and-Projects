
/***************************************************************************
 *  Programmers and Purdue Email Addresses:
 *  1. chen3124@purdue.edu
 *  2. chu171@purdue.edu
 *  3. cfrielin@purdue.edu
 *
 *  Lab #: 03
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Day, Time, Location of Lab: Tuesday, 9:30am , SC 189
 *
 *  Program Description: Finds the force of tension, mass per unit of length, velocity of wave generated and time to travel string length from length of string, mass of block maintaining tension, and either string mass or velocity of wave. 
 *
 ***************************************************************************/

#include<stdio.h>
#include<math.h>
#define GRAVITY 9.8 //gravitational constant(meters per second squared)

int main()
{
  //variable declaration
  double lengthString = 0; //length of string(meter)
  double massBlock = 0; //mass of block(kg)
  double selection = 0; //selection number
  double selectionnumber = 0; //value from selection number(kg or meters per second)
  double massString = 0; //mass of the string(kg)
  double velocity = 0; //velocity(meters per second)
  double force = 0; //force of tension(N)
  double massPerUnit = 0; //mass per unit of length (kg/m)
  double time = 0; //time to travel string length (s)
  double mu1 = 0; //first possible mass per unit of length value (kg/m)
  double mu2 = 0; //second possible mass per unit of length value (kg/m)
  
  //asks and gets values for length of string and mass of block
  printf("Enter length of string (m) -> ");
  scanf("%lf",&lengthString);
  printf("Enter mass of block maintaining tension (kg) -> ");
  scanf("%lf",&massBlock);

  //asks and gets values for selection number and value gained from selection number
  printf("\n1. Enter string mass\n2. Enter velocity of wave\n");
  printf("\nMake your selection -> ");
  scanf("%lf",&selection);
  printf("Enter value for selection -> ");
  scanf("%lf",&selectionnumber);

  //subtracts 1 from selection to get either 0(String mass) or 1(Velocity of wave)
  selection--;
  //separates mass of string and velocity
  massString = selectionnumber * (1 - selection);
  velocity = selectionnumber * selection;

  //calculates force
  force = massBlock * GRAVITY;
  
  //calculates two possible mass per unit of length from different equations
  mu1 = (force / ((velocity * velocity) + (1 - selection))) * selection;
  mu2 = (massString / lengthString) * (1 - selection);

  //calculates the mass per unit and compensates for divide by zero protection above
  mu1 = mu1 * selection;
  massPerUnit = mu1 + mu2;

  //calculates the mass of the string
  massString = (selectionnumber * (1 - selection)) + (lengthString * massPerUnit * (selection));
  //calculates the velocity of the wave generated
  velocity = (selectionnumber * selection) + (sqrt(force / massPerUnit)) * (1 - selection);
  
  //calculates the time to travel string length
  time = (lengthString - 1) / velocity;
  
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nMass of string:%11.1lf (kg)",massString);
  printf("\nLength of string:%9.1lf (m)",lengthString);
  printf("\nMass of block:%12.1lf (kg)",massBlock);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nForce of tension:%9.1lf (N)",force);
  printf("\nMass per unit of length:%16.3lf (kg/m)",massPerUnit);
  printf("\nVelocity of wave generated:%11.1lf (m/s)",velocity);
  printf("\nTime to travel string length:%11.3lf (s)", time);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return (0);
}

