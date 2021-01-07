#include<stdio.h>
#include<math.h>

void angleInput(double *angle1, double *angle2, double *angle3);
void sideInput(double *side1, double *side2, double *side3);
void lawSines(double *angle1, double *angle2, double *angle3, double *side1, double *side2, double *side3);
void angleFiller(double *angle1, double *angle2, double *angle3, double *side1, double *side2, double *side3);
void sideFiller(double *angle1, double *angle2, double *angle3, double *side1, double *side2, double *side3);
double areaFinder(double side1, double side2, double side3);
void output(double angle1, double angle2, double angle3, double side1, double side2, double side3, double area);
int main ()
{
  //variable declaration
  double angle1;
  double angle2;
  double angle3;
  double side1;
  double side2;
  double side3;
  double area;

  //execution statements
  angleInput(&angle1, &angle2, &angle3);
  sideInput(&side1, &side2, &side3);
  lawSines(&angle1, &angle2, &angle3, &side1, &side2, &side3);
  angleFiller(&angle1, &angle2, &angle3, &side1, &side2, &side3);
  sideFiller(&angle1, &angle2, &angle3, &side1, &side2, &side3);
  area = areaFinder(side1, side2, side3);
  output(angle1, angle2, angle3, side1, side2, side3, area);
}

void angleInput(double *angle1, double *angle2, double *angle3)
{
  printf("Enter angle measurements [degrees] -> ");
  scanf("%lf %lf %lf", angle1, angle2, angle3);
  *angle1 = *angle1 * M_PI / 180;
  *angle2 = *angle2 * M_PI / 180;
  *angle3 = *angle3 * M_PI / 180;
}

void sideInput(double *side1, double *side2, double *side3)
{
    printf("Enter side lengths [cm] -> ");
    scanf("%lf %lf %lf", side1, side2, side3);
}

void lawSines(double *angle1, double *angle2, double *angle3, double *side1, double *side2, double *side3)
{
    if (*angle1 !=0 && *side1 != 0) //If angle1 and side1 both exist
    {
        if(*angle2 == 0 && *side2 != 0) //Finds angle2
        {
            *angle2 = asin(*side2 * sin(*angle1) / *side1);
        }
        else if(*angle2 != 0 && *side2 == 0) //Finds side2
        {
            *side2 = (*side1 * sin(*angle2)) / sin(*angle1);
        }
        else if(*angle3 == 0 && *angle3 !=0) //Finds angle3
        {
            *angle3 = asin(*side3 * sin(*angle1) / *side1);
        }
        else //Finds side3
        {
            *side3 = (*side1 * sin(*angle3)) / sin(*angle1);
        }
    }
    else if(*angle2 != 0 && *side2 != 0) //If angle2 and side2 both exist
    {
        if(*angle1 == 0 && *side1 != 0) //Finds angle1
        {
            *angle1 = asin(*side1 * sin(*angle2) / *side2);
        }
        else if(*angle1 != 0 && *side1 == 0) //Finds side1
        {
            *side1 = (*side2 * sin(*angle1)) / sin(*angle2);
        }
        else if(*angle3 == 0 && side3 != 0) //Finds angle3
        {
            *angle3 = asin(*side3 * sin(*angle2) / *side2);
        }
        else //Finds side3
        {
            *side3 = (*side2 * sin(*angle3)) / sin(*angle2);
        }
    }
    else //If angle3 and side3 both exist
    {
        if(*angle1 == 0 && *side1 != 0) //Finds angle1
        {
            *angle1 = asin(*side1 * sin(*angle3) / *side3);
        }
        else if(*angle1 != 0 && *side1 == 0) //Finds side1
        {
            *side1 = (*side3 * sin(*angle1)) / sin(*angle3);
        }
        else if(*angle2 == 0 && *side2 != 0) //Finds angle2
        {
            *angle2 = asin(*side2 * sin(*angle3) / *side3);
        }
        else //Finds side2
        {
            *side2 = (*side3 * sin(*angle2)) / sin(*angle3);
        }
    }
}

void angleFiller(double *angle1, double *angle2, double *angle3, double *side1, double *side2, double *side3)
{
    double counter = 0;
    if(*angle1 == 0)
    {
        counter++;
    }
    if(*angle2 == 0)
    {
        counter++;
    }
    if(*angle3 == 0)
    {
        counter++;
    }
    if (counter == 1)
    {
        if(*angle1 == 0)
        {
            *angle1 = M_PI - (*angle2 + *angle3);
        }
        if(*angle2 == 0)
        {
            *angle2 = M_PI - (*angle1 + *angle3);
        }
        else
        {
            *angle3 = M_PI - (*angle1 + *angle2);
        }
    }
}

void sideFiller(double *angle1, double *angle2, double *angle3, double *side1, double *side2, double *side3)
{
	double counter = 0;
	if(*side1 == 0)
	{
		counter++;
	}
	if(*side2 == 0)
	{
		counter++;
	}
	if(*side3 == 0)
	{
		counter++;
	}
	if (counter == 1)
	{
		if(*side1 == 0)
		{
			if(*angle2 != 0)
			{
				*side1 = (*side2 * sin(*angle1)) / sin(*angle2);
			}
			else
			{
				*side1 = (*side3 * sin(*angle1)) / sin(*angle3);
			}
		}
		if(*side2 == 0)
		{
			if(*angle1 != 0)
			{
				*side2 = (*side1 * sin(*angle2)) / sin(*angle1);
			}
			else
			{
				*side2 = (*side3 * sin(*angle2)) / sin(*angle3);
			}
		}
		if(*side3 == 0)
		{
			if(*angle1 != 0)
			{
				*side3 = (*side1 * sin(*angle3)) / sin(*angle1);
			}
			else
			{
				*side3 = (*side2 * sin(*angle3)) / sin(*angle2);
			}
		}
	}
}

double areaFinder(double side1, double side2, double side3)
{
    double halfperimeter;
    double area;
    halfperimeter =  (side1 + side2 + side3) / 2;
    area = sqrt(halfperimeter * (halfperimeter-side1) * (halfperimeter-side2) * (halfperimeter-side3));

    return area;
}

void output(double angle1, double angle2, double angle3, double side1, double side2, double side3, double area)
{
    angle1 = angle1 * 180 / M_PI;
    angle2 = angle2 * 180 / M_PI;
    angle3 = angle3 * 180 / M_PI;
    printf("\n\nAngle measurements [degrees]: %.2lf %.2lf %.2lf", angle1, angle2, angle3);
    printf("\nSide lengths [centimeters]: %.2lf %.2lf %.2lf", side1, side2, side3);
    printf("\nArea of triangle [centimeters squared]: %.2lf", area);
}
