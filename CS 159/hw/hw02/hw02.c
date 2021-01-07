
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3124@purdue.edu
*
*  Homework #:02
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30 AM, SC 189
*
*  Program Description: Finds the observed frequency of an emergency vehicle from a second vehicle while approaching and moving away either from a travelling or stationary point of view
*
***************************************************************************/

#include<stdio.h>

//defines constants used later
#define SPEEDSOUND 345 //speed of sound
#define MILESMETERSCONVERT 0.447 //conversion factor between miles per hour and meters per second

int main()
{
  //variable declaration
  double carspeed1 = 0; //stores the emergency car's speed in miles per hour 
  double carspeed1meters = 0; //stores the speed of the emergency car in meters per second
  double carspeed2meters = 0; //stores the speed of the second car in meters per second
  double frequencyapproach = 0; //stores the frequency of the approach
  double frequencyaway = 0; //stores the frequency when moving away
  double sirenfrequency = 0; //stores the frequency of the siren
  char SorT = 0; //stores char value of s or t

  //asks and scans for stationary/travelling
  printf("Enter whether observer is (S)tationary or (T)raveling -> ");
  scanf("%c",&SorT);

  //asks and scans for two variables on the speed of the cars
  printf("Enter speed [miles/hr] of emergency vehicle -> ");
  scanf("%lf",&carspeed1);
  
  //asks and scans for the frequency of the vehicle
  printf("Enter frequency [Hz] of siren -> ");
  scanf("%lf",&sirenfrequency);

  //converts between miles per hour and meters per second
  carspeed1meters = carspeed1 * MILESMETERSCONVERT;
  carspeed2meters = carspeed1 * MILESMETERSCONVERT * ((int)SorT / 84);
  
  //calculates the frequency during approach
  frequencyapproach = sirenfrequency * ( ( SPEEDSOUND + carspeed2meters ) / ( SPEEDSOUND - carspeed1meters ) );
  frequencyaway = sirenfrequency * ( ( SPEEDSOUND - carspeed2meters ) / ( SPEEDSOUND + carspeed1meters ) );

  //prints the observed frequencies for approach and away
  printf("\nObserved frequency during approach %.1lf Hz", frequencyapproach);
  printf("\nObserved frequency moving away %.1lf Hz\n", frequencyaway);

  return 0;
}

