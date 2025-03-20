#include <stdio.h>
int main()
{
  int n, m, i;
  int array1[3];
  int array2[3];
  int array3[6];
  printf("no of elements in first array\n");
  scanf("%d", &n);
  printf("enter the elements\n");
  for (i = 0; i < n; i++)
    scanf("%d", &array1[i]);
  printf("no of elements in second array\n");
  scanf("%d", &m);
  printf("enter the elements\n");
  for (i = 0; i < m; i++)
    scanf("%d", &array2[i]);
  for (i = 0; i < n; i++)
    array3[i] = array1[i];
  for (i = 0; i < m; i++)
    array3[(n) + i] = array2[i];
  printf("merged array is\n");
  for (i = 0; i < n + m; i++)
    printf("%d", array3[i]);
}