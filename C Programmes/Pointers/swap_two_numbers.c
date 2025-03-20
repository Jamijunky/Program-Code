#include <stdio.h>
int main()
{
  int num1, num2;
  printf("enter the numbers\n");
  scanf("%d\t%d", &num1, &num2);
  int *ptr1 = &num1;
  int *ptr2 = &num2;
  int *ptr3 = ptr1;
  ptr1 = ptr2;
  ptr2 = ptr3;
  printf("first number is %d and second number is %d\n", *ptr1, *ptr2);
  return 0;
}