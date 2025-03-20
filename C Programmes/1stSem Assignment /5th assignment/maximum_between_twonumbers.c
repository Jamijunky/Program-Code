#include<stdio.h>
int main()
{
  int a;
  int *ptr1=&a;
  printf("Enter a number: ");
  scanf("%d", &a);
  int b;
  int *ptr2=&b;
  printf("Enter another number: ");
  scanf("%d", &b);
  printf("maximum of two numbers is %d ", (*ptr1>*ptr2)?*ptr1:*ptr2);
return 0; 
}