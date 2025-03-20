#include<stdio.h>
#include<string.h>
int main()
{
  int temp=0;
  char str[]="Hey there, Nice meating you";
  for(int i = 0; i<strlen(str); i++)
  {
    if(str[i] == 'a' || str[i] == 'A')
      temp++;
    if(str[i] == 'e' || str[i] == 'E')
      temp++;
    if(str[i] == 'i' || str[i] == 'I')
      temp++;
    if(str[i] == 'o' || str[i] == 'O')
      temp++;
    if(str[i] == 'u' || str[i] == 'U')
      temp++;

  }
  printf("Number of vowels in the given string: %d", temp);
  return 0;
}