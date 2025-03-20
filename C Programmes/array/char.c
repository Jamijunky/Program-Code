#include <stdio.h>
void array(char array0[5]) ;
int main()
{
  char array1[5];
  array(array1);
  for (int i = 0; i < 5; i++)
  {
    printf("%c", array1[i]);
  }
  return 0;
}

void array(char array1[5])
{
  printf("enter the character\n");
  for (int i = 0; i < 5; i++){
  scanf("%c", &array1[i]);
  }
}