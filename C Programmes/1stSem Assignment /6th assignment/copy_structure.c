#include <stdio.h>
#include <string.h>
struct person
{
  char name[20];
  int age;
  char gender;
  long long phone_number;
};

int main()
{
  struct person p1 = {"Jami", 19, 'M', 1234567890LL};
  struct person p2, p3;
  p2 = p1;
  printf("p2\n");
  printf("name: %s\n", p2.name);
  printf("age: %d\n", p2.age);
  printf("gender: %c\n", p2.gender);
  printf("phone number: %lld\n", p2.phone_number);

  strcpy(p3.name, p1.name);
  p3.age = 18;
  p3.phone_number = 87654321;
  p3.gender = p1.gender;
  printf("p3\n");
  printf("name: %s\n", p3.name);
  printf("age: %d\n", p3.age);
  printf("gender: %c\n", p3.gender);
  printf("phone number: %lld\n", p3.phone_number);
  return 0;
}