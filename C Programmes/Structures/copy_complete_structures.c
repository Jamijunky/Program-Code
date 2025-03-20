#include <stdio.h>
#include <string.h>
typedef struct person
{
  char name[50];
  int age;
  char address[100];
  char email[50];
  float weight;
  int phoneNumber;

} p;

int main()
{
  p person1;

  printf("enter name:");
  scanf("%49s", person1.name);
  printf("enter age:");
  scanf("%d", &person1.age);
  printf("enter address:");
  scanf("%99s", person1.address);
  printf("enter email:");
  scanf("%49s", person1.email);
  printf("enter weight:");
  scanf("%f", &person1.weight);
  printf("enter phone number:");
  scanf("%d", &person1.phoneNumber);
  p person2 = person1;
  strcpy(person1.name, "Jami");
  person2.age = 19;
  printf("person 2 database\n");
  printf("Name:%s\n", person2.name);
  printf("Age:%d\n", person2.age);
  printf("address:%s\n", person2.address);
  printf("Email:%s\n", person2.email);
  printf("Weight:%f\n", person2.weight);
  printf("Phone Number:%d\n", person2.phoneNumber);
  // can also make another structure and copy first structure to other.

  return 0;
}