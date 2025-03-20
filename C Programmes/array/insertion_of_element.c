#include <stdio.h>
int main()
{
  int array[50],position,c,n,value;
  printf("enter number of elements in the array\n");
  scanf("%d",&n);
  printf("enter %d elements\n",n);
  for(c=0;c<n;c++)
  scanf("%d",&array[c]);
  printf("Please enter the location where you want to enter the new element\n");
  scanf("%d",&position);
  printf("please enter the value\n");
  scanf("%d",&value);
  for(c=n-1;c>=position-1;c--)
  array[c+1]=array[c];
  array[position-1]=value;
  for(c=0;c<n+1;c++)
  printf("new array is %d",array[c]);

}