#include <stdio.h>
int main()
{int r,c;
printf("enter no of rows\n");
  scanf("%d",&r);
printf("enter no of columns\n");
  scanf("%d",&c);
  int array1[r][c];
  int i, j;
  printf("enter the elements of array\n");
  for(i=0;i<r;i++)
  for(j=0;j<c;j++)
  scanf("%d",&array1[i][j]);
  int array2[r][c];
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
      array2[j][i] = array1[j][i];
  }
  printf("transpose of matrix is\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
      printf("%d", array2[j][i]);
  }
  return 0;
}