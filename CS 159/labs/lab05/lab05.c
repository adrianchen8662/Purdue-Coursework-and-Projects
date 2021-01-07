
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. chen3124@purdue.edu
*  2. joshi99@purdue.edu
*  3. carte277@purdue.edu
*
*  Lab #: 05
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday, 9:30AM, SC189
*
*  Program Description: Finds the distance, angle, orthogonal components, force components, net force and angle of net force using charges and two x-y coordinates
*
***************************************************************************/

#include<stdio.h>
#include<math.h>
#define COULOMB (8.99 * pow(10,9)) //Stores Coulomb's Constant

//function declaration
double inputCharge(double counter);
void inputCoord(double counter, double *xCoord, double *yCoord);
double distanceFinder(double xvector, double yvector);
double coulombForce(double charge1, double charge2, double radius);
double angleFinder(double xvector, double yvector);
double resultantForce(double xforce, double yforce);
double orthogonalxforce(double angle, double force);
double orthogonalyforce(double angle, double force);
double forceFinder(double netforce, double orthogonalcomponent);
void outputDisplay(double distance12, double angle12, double distance13, double angle13, double orthogonalx12, double orthogonaly12, double orthogonalx13, double orthogonaly13, double forcex, double forcey, double netforce, double netforceangle);

int main()
{
  //variable declaration
  double charge1; //stores charge 1[micro-Coulomb]
  double charge2; //stores charge 2[micro-Coulomb]
  double charge3; //stores charge 3[micro-Coulomb]
  double xCoord2 = 0; //stores x coordinate of charge 2[cm]
  double yCoord2 = 0; //stores y coordinate of charge 2[cm]
  double xCoord3 = 0; //stores x coordinate of charge 3[cm]
  double yCoord3 = 0; //stores y coordinate of charge 3[cm]
  double distance12; //stores the distance between 1 and 2[cm]
  double angle12 = 0; //stores the angle between 1 and 2[degrees]
  double distance13 = 0; //stores the distance between 1 and 3[cm]
  double angle13 = 0; //stores the angle between 1 and 3[cm]
  double force12 = 0; //stores the force between 1 and 2[N]
  double force13 = 0; //stores the force between 1 and 3[N]
  double orthogonalx12; //stores the x component of 1 and 2 - No units
  double orthogonaly12; //stores the y component of 1 and 2 - No units
  double orthogonalx13; //stores the x component of 1 and 3 - No units
  double orthogonaly13; //stores the y component of 1 and 3 - No units
  double forcex = 0; //stores the net force in the x direction[N]
  double forcey = 0; //stores the net force in the y direction[N]
  double netforce; //stores the net force[N]
  double netforceangle; //store the net force angle[degrees]
  double counter = 1; //stores a counter for inputs

  //execution statements
  //asks for charges and increments counter by 1
  charge1 = inputCharge(counter);
  counter++;
  charge2 = inputCharge(counter);
  counter++;
  charge3 = inputCharge(counter);

  //resets counter, asks for coordinates and increments counter by 1
  counter = 2;
  inputCoord(counter, &xCoord2, &yCoord2);
  counter++;
  inputCoord(counter, &xCoord3, &yCoord3);
  
  //finds the distances and angles between 1 and 2, and 1 and 3
  distance12 = distanceFinder(xCoord2, yCoord2);
  angle12 = angleFinder(xCoord2, yCoord2);
  distance13 = distanceFinder(xCoord3, yCoord3);
  angle13 = angleFinder(xCoord3, yCoord3);
  
  //finds the force between 1 and 2, and 1 and 3 using Coulomb's Law
  force12 = coulombForce(charge1, charge2, distance12);
  force13 = coulombForce(charge1, charge3, distance13);
  
  //finds the orthogonal ratio for x and y between 1 and 2, and 1 and 3
  orthogonalx12 = orthogonalxforce(angle12, force12);
  orthogonaly12 = orthogonalyforce(angle12, force12);
  orthogonalx13 = orthogonalxforce(angle13, force13);
  orthogonaly13 = orthogonalyforce(angle13, force13);

  //finds the net forces in the x and y direction
  forcex = forceFinder(orthogonalx12, force12) + forceFinder(orthogonalx13, force13);
  forcey = forceFinder(orthogonaly12, force12) + forceFinder(orthogonaly13, force13);
  
  //finds the net force and net force angle
  netforce = distanceFinder(forcex, forcey);
  netforceangle = angleFinder(forcex, forcey);

  //sends the neccessary outputs to be displayed
  outputDisplay(distance12, angle12, distance13, angle13, orthogonalx12, orthogonaly12, orthogonalx13, orthogonaly13, forcex, forcey, netforce, netforceangle);

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputCharge
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double counter - counter for which input is being inputted
*
*  Function Description: Gets input for charges
*
***************************************************************************/

double inputCharge(double counter)
{
  //local variables
  double input; //counter for which input is being inputted

  //execution statements
  printf("Enter charge [micro-Coulomb] for point #%0.0lf -> ", counter);
  scanf("%lf",&input);

  return(input);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputCoord
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double counter - counter for which input is being inputted 
*    2. double xCoord - stores the x coordinate
*    3. double yCoord - stores the y coordinate
*
*  Function Description: Gets ordered pairs for charge location
*
***************************************************************************/

void inputCoord(double counter, double *xCoord, double *yCoord)
{

  //execution statements
  printf("Enter x coordinate [cm] of point #%0.0lf -> ", counter);
  scanf("%lf",xCoord);
  printf("Enter y coordinate [cm] of point #%0.0lf -> ", counter);
  scanf("%lf",yCoord);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: distanceFinder
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double xvector - takes in a vector
*    2. double yvector - takes in another vector
*
*  Function Description: Finds the distance between two points
*
***************************************************************************/

double distanceFinder(double xvector, double yvector)
{
  //local variables
  double distance; //stores the distance calculated[cm]

  //execution statements
  distance = sqrt(pow(xvector, 2) + pow(yvector, 2));

  return distance;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: coulombForce
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double charge1 - charge of particle 2
*    2. double charge2 - charge of particle 2
*    3. double radius - distance between charge 1 and charge 2
*
*  Function Description: finds the force between to particles using Coulomb's Law
*
***************************************************************************/

double coulombForce(double charge1, double charge2, double radius)
{
  //local variables
  double force; //stores the force calculated[N]
  
  //execution statements
  charge1 = fabs(charge1 * pow(10,-6));
  charge2 = fabs(charge2 * pow(10,-6));
  radius = radius / 100;

  force = COULOMB * (charge1 * charge2) / pow(radius, 2);

  return(force);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: angleFinder
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double xvector - takes in a vector
*    2. double yvector - takes in another vector
*
*  Function Description: Finds the angle between two vectors
*
***************************************************************************/

double angleFinder(double xvector, double yvector)
{
  //local variables
  double angle; //stores the angle calculated[degrees]

  //execution statements
  angle = (180 / M_PI) * atan(yvector / xvector);
  
  return(angle);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: orthogonalxforce
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double angle - angle between two particles
*    2. double force - force obtained from Coulomb's Law
*
*  Function Description: Finds the orthogonal ratio in the x direction
*
***************************************************************************/

double orthogonalxforce(double angle, double force)
{
  //local variables
  double orthogonalx; //stores the orthogonal ratio in the x direction[unitless]
  
  //execution statements
  orthogonalx = cos(angle * (M_PI / 180));

  return orthogonalx;
}

/***************************************************************************
*
*  Function Information:
*
*  Name of Function: orthogonalyforce
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double angle - angle between two particles
*    2. double force - force obtained from Coulomb's Law
*
*  Function Description: Finds the orthogonal ratio in the y direction
*
***************************************************************************/

double orthogonalyforce(double angle, double force)
{
  //local variables
  double orthogonaly; //stores the orthogonal ratio in the y direction[unitless]
  
  //execution statements
  orthogonaly = sin(angle * (M_PI / 180));

  return orthogonaly;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: forceFinder
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double force - force to be split into components
*    2. double orthogonalcomponent - ratio to be multiplied
*
*  Function Description: Finds the x or y component to forces
*
***************************************************************************/

double forceFinder(double force, double orthogonalcomponent)
{
  //local variables
  double forceoutput; //stores the force[N]

  //execution statements
  forceoutput = force * orthogonalcomponent;

  return forceoutput;
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
*    1. double distance12 - distance between point 1 and 2
*    2. double angle12 - angle between point 1 and 2
*    3. double distance13 - distance between point 1 and 3
*    4. double angle13 - angle between point 1 and 3
*    5. double orthogonalx12 - orthogonal x ratio between point 1 and 2
*    6. double orthogonaly12 - orthogonal y ratio between point 1 and 2
*    7. double orthogonalx13 - orthogonal x ratio between point 1 and 3
*    8. double orthogonaly13 - orthogonal y ratio between point 1 and 3
*    9. double forcex - force in the x component
*    10. double forcey - force in the y component
*    11. double netforce - net force
*    12. double netforceangle - net force angle
*
*  Function Description: Output's the variables required
*
***************************************************************************/

void outputDisplay(double distance12, double angle12, double distance13, double angle13, double orthogonalx12, double orthogonaly12, double orthogonalx13, double orthogonaly13, double forcex, double forcey, double netforce, double netforceangle)
{
  //execution statements
  printf("Distance [cm] and Angle [degrees] from point 1 to 2: %0.1lf, %0.1lf", distance12, angle12);
  printf("\nDistance [cm] and Angle [degrees] from point 1 to 3: %0.1lf, %0.1lf", distance13, angle13);
  printf("\n\nOrthogonal components point 1 to point 2 [x, y]: %0.3lf, %0.3lf", orthogonalx12, orthogonaly12);
  printf("\nOrthogonal components point 1 to point 3 [x, y]: %0.3lf, %0.3lf", orthogonalx13, orthogonaly13);
  printf("\n\nForce [N] of x and y direction: %0.3lf, %0.3lf", forcex, forcey);
  printf("\nNet force [N] and angle [degrees]: %0.3lf, %0.1lf\n", netforce, netforceangle);
}
