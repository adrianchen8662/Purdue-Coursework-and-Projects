
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3124@purdue.edu
*  2. chu171@purdue.edu
*  3. cfrielin@purdue.edu
*
*  Lab #: 1
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tue, 9:30 AM, SC 189
*
*  Program Description: Finds the perpendicular bisector from two ordered pairs
*
***************************************************************************/

#include<stdio.h>

int main()
{
  //variable declaration
  float x1 = 0; //ordered pair 1, x variable
  float y1 = 0; //ordered pair 1, y variable
  float x2 = 0; //ordered pair 2, x variable
  float y2 = 0; //ordered pair 2, y variable
  float midpointx = 0; //midpoint, x variable
  float midpointy = 0; //midpoint, y variable
  float slope = 0; //slope
  float yintercept = 0; //y-interecpt of equation

  //asks and scans for four variables for two ordered pairs
  printf("Enter the first x coordinate -> ");
  scanf("%f",&x1);
  printf("Enter the first y coordinate -> ");
  scanf("%f",&y1);
  printf("Enter the second x coordinate -> ");
  scanf("%f",&x2);
  printf("Enter the second y coordinate -> ");
  scanf("%f",&y2);
  
  //prints the two ordered pairs, formatted to one decimal space
  printf("Original endpoints: [%.1f, %.1f] and [%.1f, %.1f]", x1, y1, x2, y2);
  
  //finds the midpoint, slope and y-intercept
  midpointx = (x1 + x2) / 2;
  midpointy = (y1 + y2) / 2;
  slope = (y2 - y1) / (x2 - x1);
  slope = -1 / slope; //creates the negative inverse of the parallel slope
  yintercept = midpointy - slope * midpointx;

  //prints out the equation of the perpendicular bisector in y-intercept form, formatted to two decimal spaces
  printf("\nEquation of the perpendicular bisector: y = %.2fx + %.2f\n", slope, yintercept);
 
  return(0);

}
