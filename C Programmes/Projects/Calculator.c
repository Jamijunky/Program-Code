#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int parameter()
{
  int choice;
  printf("Enter 1 for Addition\nEnter 2 for Subtraction\nEnter 3 for Multiplication\nEnter 4 for Division\nEnter 5 for Modulus\nEnter 6 for power\n");
  printf("Enter the choice: ");
  scanf("%d", &choice);
  return choice;
}

void again()
{
  int wish;
  printf("Do You Wanna Go again? Enter 1 for Yes and 0 for No \n");
  scanf("%d", &wish);
  if (wish == 0)
  {
    printf("Thank You For Using My Calculator\n");
    exit(0);
  }
  else if (wish != 0 && wish != 1)
  {
    printf("Enter only either 1 or 0\n");
    again();
  }
  else if (wish == 1)
  {
     printf("----------------------------------------------------\n");
    return ;
  }

}

int main()
{

  float num1, num2;

  printf("Welcome to my simple calculator\n");
  while (1)
  {
    int option = parameter();

    if (0 < option && option < 7)
    {
      printf("Enter the first number: ");
      scanf("%f", &num1);
      printf("Enter the second number: ");
      scanf("%f", &num2);
    }
    else
    {
      printf("Enter a valid option:\n");
      parameter();
    }

    switch (option)
    {
    case 1:
      printf("Sum of %f and %f is %f\n", num1, num2, num1 + num2);
      break;
    case 2:
      printf("Difference of %f and %f is %f\n", num1, num2, num1 - num2);
      break;
    case 3:
      printf("Product of %f and %f is %f\n", num1, num2, num1 * num2);
      break;
    case 4:
      if (num2 == 0)
        printf("Error: Division by zero\n");
      else
        printf("Quotient of %f and %f is %f\n", num1, num2, num1 / num2);
      break;
    case 5:
      printf("Modulus of %f and %f is %d\n", num1, num2, (int)num1 % (int)num2);
      break;
    case 6:
      printf("Power of %f and %f is %f\n", num1, num2, pow(num1, num2));
      break;
    }

    again();
  }

  return 0;
}