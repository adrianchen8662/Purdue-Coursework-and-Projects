//Constant time example - The time will always be the same no matter what the array contains
int ConstantTime (int arr[])
{
  return(arr[0]);
}

//Linear time example - The time will scale linearly with the size of the array
void LinearTime (int arr[], int size)
{
  int x;
  for(int i = 0; i < size; i++)
  {
    if(arr[i] == x)
    {
      printf("Match found!");
  }
}

//Quadratic time example - The time will scale by the power of 2 with the size of the array
void QuadraticTime (int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (arr[i] == arr[j])
      {
        printf("Match found\n");
      }
    }
  }
}

//Exponential time - The time will scale exponentially with how many digits you want in the fibonacci sequence
int ExponentialTime (int num)
{
  if (num <= 1)
  {
    return ExponentialTime(num - 2) + Exponentialtime(num - 1);
  }
}
