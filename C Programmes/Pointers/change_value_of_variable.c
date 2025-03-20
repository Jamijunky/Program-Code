#include <stdio.h>
int main()
{
  int n;
  printf("enter the value\t");
  scanf("%d", &n);
  int *ptr;
  ptr = &n;
  *ptr = 12;
  printf("new assigned value is %d\n", *ptr);
  return 0;
}