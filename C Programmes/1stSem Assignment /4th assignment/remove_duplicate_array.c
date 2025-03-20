
#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        
        for (int k = j; k < n - 1; k++)
        {
          arr[k] = arr[k + 1];
        }
        n--; 
        j--; 
      }
    }
  }
  printf("\nArray after removing duplicates:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}
int main()
{
  int n;
  printf("Enter the size of array: ");
  scanf("%d", &n);
  printf("Enter the elements of array:\n");
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Original array:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  removeDuplicates(arr, n);
}
