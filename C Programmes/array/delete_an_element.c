#include <stdio.h>
int main()
{
  int n;
  printf("size of array\n");
  scanf("%d",&n);
  int array[n];
  printf("enter the elements\n");
  int size=sizeof(array)/sizeof(array[0]);
  for(int i=0;i<n;i++)
  scanf("%d",&array[i]);
  int element;
  printf("element to delete\n");
  scanf("%d", &element);
  printf("new array\n");
  for (int i = element; i <=size ; i++)
    array[i - 1] = array[i];
  for (int i = 1; i < size; i++)
    printf("%d\n", array[i - 1]);

  return 0;
}
