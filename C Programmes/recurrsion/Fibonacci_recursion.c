#include <stdio.h>
int fibon(int n)
{
  if (n <= 1)
    return n;
  else
    return fibon(n-1) + fibon(n-2);
}
int main()
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  int result=fibon(num);
  printf("%d",result);
}