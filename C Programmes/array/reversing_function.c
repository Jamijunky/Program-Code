#include <stdio.h>
int reverse_array(int a, int array[a])
{
  int array2[a];
  int i;
  for (i = a - 1; i >= 0; i--)
    array2[(a- 1) - i] = array[i];
    printf("reversed array is\n");
  for (i = 0; i < a; i++)
    printf("%d ", array2[i]);
  return 0;
}

int main()
{
  int n;
  printf("total size of array\n");
  scanf("%d", &n);
  int array1[n];
  printf("enter the array\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &array1[i]);
  }
  reverse_array(n,array1);
}
