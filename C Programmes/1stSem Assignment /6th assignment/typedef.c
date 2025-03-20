#include <stdio.h>
#include <string.h>
typedef struct person //Typdef make alias for struct person
{
  char name[20];
  int age;
  char gender;
  long long phone_number;
}p;

int main()
{
  p p1= {"Jami", 19, 'M', 1234567890LL}; 
  p p2;
  p2 = p1;
  printf("p2\n");  
  printf("name: %s\n", p2.name);
  printf("age: %d\n", p2.age);
  printf("gender: %c\n", p2.gender);
  printf("phone number: %lld\n", p2.phone_number);
  return 0;
}