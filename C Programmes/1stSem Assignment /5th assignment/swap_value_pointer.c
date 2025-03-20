#include<stdio.h>
int swapping(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  printf("After swapping: a = %d, b = %d\n", *a, *b);
  return 0;  // Returning 0 to indicate successful swapping.
}
int main()
{
  int a=5;
  int b=10;
  swapping(&a, &b);
}