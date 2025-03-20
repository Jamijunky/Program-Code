#include<stdio.h>
#include<string.h>
int main()
{
  char string1[]="My name is Jami";
  char string2[20];
  printf("copying string with string function\n");
  strcpy(string2, string1);
  printf("%s",string2);
  printf("\ncopying string without string function\n");
  for(int i=0; i<strlen(string1); i++)
  {
    string2[i]=string1[i];
    printf("%c",string2[i]);
  }



  return 0;
}