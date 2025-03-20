#include<stdio.h>
int main()
{
  int n,m;
  printf("Enter the size of first array\n");
  scanf("%d",&n);
  printf("Enter the size of second array\n");
  scanf("%d",&m);
  int arr1[n],arr2[m];
  printf("Enter the elements of first array\n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr1[i]);
  printf("Enter the elements of second array\n");
  for(int i=0;i<m;i++)
    scanf("%d",&arr2[i]);
    
    int arr3[n+m];
    for(int i=0;i<n+m;i++)
    {
      if(i<n)
        arr3[i]=arr1[i];
      else
        arr3[i]=arr2[i-n];
 
    }
     for(int i=0;i<n+m;i++)
     {
      for(int j=0;j<n+m-1;j++)
      {
      if(arr3[j]>arr3[j+1])
      {
        int temp=arr3[j];
        arr3[j]=arr3[j+1];
        arr3[j+1]=temp;
      }
      }
      
     }
      printf("Merged array is\n");
      for(int i=0;i<n+m;i++)
      {
        printf("%d, ",arr3[i]);
      }
      return 0;
     }

   

     
