#include <stdio.h>
int main()
{
  int array[5];
  int *ptr = &array[0];
  printf("enter the elements\n");
  int i;
  for (i = 0; i < 5; i++)
    scanf("%d", (ptr + (4 * i)));
    printf("entered elements are\n");
  for (i = 0; i < 5; i++)
    printf("%d\n",*(ptr+(4*i)));
  return 0;
}