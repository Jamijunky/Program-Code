#include <stdio.h>
int main()
{
  int arr[3][3] = {1, 2, 3, 2, 3, 1, 3, 1, 2};

  int arr_add[3][3];
  int arr_multiply[3][3];
  int arr_transpose[3][3];
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      arr_multiply[i][j]=0;
      arr_add[i][j] = (arr[i][j] + arr[i][j]);
      for(int k = j; k < 3; k++)
      {
        arr_multiply[i][j] = arr_multiply[i][j]+(arr[i][k] * arr[k][i]);
      }

      arr_transpose[i][j] = arr[j][i];
    }
  }
  printf("Added array is \n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", arr_add[i][j]);
    }
    printf("\n");
  }
  printf("Multiplied array is \n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", arr_multiply[i][j]);
    }
    printf("\n");
  }
  printf("transposed array is \n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", arr_transpose[i][j]);
    }
    printf("\n");
  }
  return 0;
}