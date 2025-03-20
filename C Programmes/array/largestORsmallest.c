#include <stdio.h>
int main()
{
  int n, i;
  printf("no of elements in array\n");
  scanf("%d", &n);
  printf("enter the elements\n");
  int array[n];
  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);
  int x = array[0];
  for (i = 1; i < n; i++)
  {
    if (x <array[i])
      x = array[i];

  }
  printf("the largest element is %d\n", x);
  int y = array[0];
  for (i = 1; i < n; i++)
  {
    if (y >array[i])
      y = array[i];
  
  }
  printf("the smallest element is %d\n", y);
  return 0;
}