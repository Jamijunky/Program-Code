#include <stdio.h>
#include <string.h>
void BinaryAddition()
{
  long int num1;
  long int num2;
  printf("Enter Two Binary Numbers\n");
  printf("First Number: ");
  scanf("%ls", num1);
  printf("Second Number: ");
  scanf("%ls", num2);
  long int i = 0;
  long int ans1 = 0;
  while (num1 > 0)
  {
    long int power = (int)pow(2, i);
    ans1 += (power * (num1 % 10));
    num /= 10;
    i++;
  }
  long int j = 0;
  long int ans2 = 0;
  while (num > 0)
  {
    long int power = (int)pow(2, i);
    ans2 += (power * (num2 % 10));
    num /= 10;
    i++;
  }
  int sum = ans1 + ans2;
  char FinalSum[50];
  while (sum > 0)
  {
    if (sum % 2 == 0)
      strcat(FinalSum, '0');
    else
    {
      strcat(FinalSum, '1');
    }
    sum /= 10;
  }
  printf("Sum of %ld %ld is %s", num1,num2,FinalSum);
}
void BinarySubtraction()
{
}
int main()
{
  int option;
  printf("1) Binary Addition\n2)Binary Substraction\n");
  scanf("%d", &option);
  if (option == 1)
  {
    BinaryAddition();
  }
  else
  {
    BinarySubtraction();
  }
  return 0;
}