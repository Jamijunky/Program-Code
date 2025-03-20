#include<stdio.h>
int main()
{
  int array[3][3]={{1,2,3},{2,3,1},{3,1,2}};
  for(int i=2; i>=0; i--)
  {
    int store=array[i][2];
    for(int j=2; j>0;j--)
    {
      array[i][j]=array[i][j-1];
  }
    array[i][0]=store;
  }
  printf(" array is \n");
  for(int i=0; i<3;i++)
  {
    for(int j=0; j<3;j++)
  {
    printf("%d ", array[i][j]);
  }
  printf("\n");
  }

  return 0;
}