#include <stdio.h>
#include <stdlib.h>
void array_targetsum(int n, int target_sum, int array[n], int temp)
{
  
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = i + 2; k < n; k++)
      {
        if (array[i] + array[j] + array[k] == target_sum)
        {
          printf("Triplet with sum %d: %d, %d, %d\n", target_sum, array[i], array[j], array[k]);
          temp++;
        }
      }
    }
  }
  if (temp == 0)
  {
    printf("No triplet found with sum %d\n", target_sum);
    exit(0);
  }
  int initialized = 0;
  int target_sum_array[temp][3];
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = i + 2; k < n; k++)
      {

        if (array[i] + array[j] + array[k] == target_sum)
        {
          target_sum_array[initialized][0] = array[i];
          target_sum_array[initialized][1] = array[j];
          target_sum_array[initialized][2] = array[k];
        }
      }
      initialized++;
    }
  }
  for (int i = 0; i < temp; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (target_sum_array[i][j] > target_sum_array[i][j + 1])
      {
        int num = target_sum_array[i][j + 1];
        target_sum_array[i][j + 1] = target_sum_array[i][j];
        target_sum_array[i][j] = num;
      }
    }
  }
  printf("array is\n");
  for (int i = 0; i < temp; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", target_sum_array[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int n;
  printf("Enter the number of elements in array: ");
  scanf("%d", &n);
  printf("Enter the different elements of array:\n");
  int array[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &array[i]);
  int target_sum;
  printf("Enter the target sum: ");
  scanf("%d", &target_sum);
  int temp = 0;
  array_targetsum(n, target_sum, array, temp);
}