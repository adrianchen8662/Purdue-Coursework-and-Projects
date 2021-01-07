
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. chen3124@purdue.edu
*
*  Homework #: 03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30AM, SC189
*
*  Program Description: Finds the total distance and angle displaced from (0,0)
*
***************************************************************************/

#include<stdio.h>
#include<math.h>

//function declaration
double inputAngle(double counter); 
double inputDistance(double counter);
double xDistance(double distance, double angle);
double yDistance(double distance, double angle);
double distanceDisplacement(double Ax, double Ay);
double angleDisplacement(double Ax, double Ay);
void outputDisplay(double distancedisplaced, double angledisplaced);

int main()
{
  //variable declaration
  double angle1; //stores the first angle - degrees
  double angle2; //stores the second angle - degrees
  double angle3; //stores the third angle - degrees
  double angle4; //stores the fourth angle - degrees
  double distance1; //stores the first distance - meters
  double distance2; //stores the second distance - meters
  double distance3; //stores the third distance - meters
  double distance4; //stores the fourth distance - meters
  double totalxdistance; //stores the total x distance displaced - meters
  double totalydistance; //stores the total y distance displaced - meters
  double distancedisplaced; //stores the distance displaced from (0,0) - meters
  double angledisplaced; //stores the angle displaced from (0,0) - degrees
  double counter = 1; //counts which angle/distance is being inputted

  //execution statements
  angle1 = inputAngle(counter);
  counter++;
  angle2 = inputAngle(counter);
  counter++;
  angle3 = inputAngle(counter);
  counter++;
  angle4 = inputAngle(counter);
  counter = 1;
  distance1 = inputDistance(counter);
  counter++;
  distance2 = inputDistance(counter);
  counter++;
  distance3 = inputDistance(counter);
  counter++;
  distance4 = inputDistance(counter);

  //calculates the total x and y distance
  totalxdistance = xDistance(distance1, angle1) + xDistance(distance2, angle2) + xDistance(distance3, angle3) + xDistance(distance4, angle4);
  totalydistance = yDistance(distance1, angle1) + yDistance(distance2, angle2) + yDistance(distance3, angle3) + yDistance(distance4, angle4);

  //calculates the distance and angle displaced from (0,0)
  distancedisplaced = distanceDisplacement(totalxdistance, totalydistance);
  angledisplaced = angleDisplacement(totalxdistance, totalydistance);
  
  //returns the distance and angle displaced
  outputDisplay(distancedisplaced, angledisplaced);
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputAngle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double counter - counts which angle is being asked for
*
*  Function Description: Gets the input for angle
*
***************************************************************************/

double inputAngle(double counter)
{
  //local declaration
  double input; //stores the input

  //execution statements
  printf("Enter angle [degrees] for leg #%.0lf -> ", counter);
  scanf("%lf",&input);
  return(input);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputDistance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double counter - counts which distance is being asked for
*
*  Function Description: Gets the input for distance
*
***************************************************************************/

double inputDistance(double counter)
{
  //variable declaration
  double input; //stores the input
  
  //execution statements
  printf("Enter distance traveled [m] for leg #%0.lf -> ", counter);
  scanf("%lf",&input);
  return input;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: xDistance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double distance - stores distance
*    2. double angle - stores angle
*
*  Function Description: Finds the distance in the x-direction
*
***************************************************************************/

double xDistance(double distance, double angle)
{
  //variable declaration
  double xdist; //stores the x distance

  //execution statements
  xdist = distance * cos((M_PI / 180) * angle);
  return xdist;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: yDistance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double distance - stores distance
*    2. double angle - stores angle
*
*  Function Description: Finds the distance in the y-direction
*
***************************************************************************/

double yDistance(double distance, double angle)
{ 
  //variable declaration
  double ydist; //stores the y distance
  
  //execution statements
  ydist = distance * sin((M_PI / 180) * angle);
  return ydist;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: distanceDisplacement
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double Ax - stores the total x distance
*    2. double Ay - stores the total y distance
*
*  Function Description: Finds the total distance displacement
*
***************************************************************************/

double distanceDisplacement(double Ax, double Ay)
{
  //variable declaration
  double distancedisp; //stores the total distance displaced

  //execution statements
  distancedisp = sqrt(pow(Ax,2) + pow(Ay,2));
  return distancedisp;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: angleDisplacement
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double Ax - stores the total x direction
*    2. double Ay - stores the total y direction
*
*  Function Description: Finds the total angle displacement
*
***************************************************************************/

double angleDisplacement(double Ax, double Ay)
{
  //variable declaration
  double angledisp; //stores the total angle displaced

  //execution statements
  angledisp = (180 / M_PI) * (atan(Ay / Ax));
  return angledisp;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: outputDisplay
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double distancedisp - stores the total distance displaced
*    2. double angledisp - stores the total angle displaced
*
*  Function Description: Outputs the distance displacement and angle displacement
*
***************************************************************************/

void outputDisplay(double distancedisp, double angledisp)
{
  //execution statements
  printf("\n\nDistance displacement: %.0lf (m)", distancedisp);
  printf("\nAngle displacement: %.0lf (degrees)\n", angledisp);
}
