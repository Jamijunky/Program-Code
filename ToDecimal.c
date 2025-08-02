#include <stdio.h>
#include <math.h>
#include <string.h>
void HexaDecimal()
{
   char num[50];
   printf("Enter a HexaDecimal Number: ");
   scanf("%s", num);
   int i = 0;
   long int ans = 0;
   long int power = 1;
   for (int j = strlen(num) - 1; j >= 0; j--)
   {
      int value;
      if (num[j] >= '0' && num[j] <= '9')
         value = num[j] - '0';
      else if (num[j] >= 'A' && num[j] <= 'F')
      {
         value = num[j] - 'A' + 10;
      }
      else
      {
         printf("Enter a valid HexaDecimal Number.\n");
         return;
      }
      ans += (power * (value));
      power *= 16;

      i++;
   }
   printf("Your Decimal Number When Converting %s is %ld", num, ans);
}
void Octal()
{
   long int num;
   printf("Enter a Octal Number: ");
   scanf("%ld", &num);
   long int i = 0;
   long int ans = 0;
   while (num > 0)
   {
      long int power = (int)pow(8, i);
      ans += (power * (num % 10));
      num /= 10;
      i++;
   }
   printf("Your Decimal Number is %ld", ans);
}
void Binary()
{
   long int num;
   printf("Enter a Binary Number: ");
   scanf("%ld", &num);
   long int i = 0;
   long int ans = 0;
   while (num > 0)
   {
      long int power = (int)pow(2, i);
      ans += (power * (num % 10));
      num /= 10;
      i++;
   }
   printf("Your Decimal Number is %ld", ans);
}
int main()
{
   int option;

   printf("1) HexaDecimal \n2) Octal \n3) Binary\n");
   printf("Option: ");

   scanf("%d", &option);
   if (option == 1)
   {
      HexaDecimal();
   }
   if (option == 2)
   {
      Octal();
   }
   if (option == 3)
   {
      Binary();
   }
   return 0;
}