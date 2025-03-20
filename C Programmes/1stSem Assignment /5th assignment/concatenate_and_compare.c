#include<stdio.h>
#include<string.h>
int main()
{
  char string1[50]="My name is Jami ";
  char string2[]="I am a 1st Sem, IT student";
  strcat(string1,string2);
  printf("Concatenated string: %s",string1);
  printf("\ncomparing both strings\n");
  printf("%d",strcmp(string1,string2));


  return 0;
}  