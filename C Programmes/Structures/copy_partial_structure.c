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
typedef struct human
{
  char name[50];
  int age;
  char address[100];
  char email[50];
  float weight;
  int phoneNumber;
} h;
int main()
{
  p *ptr_person1,person1;
  ptr_person1=&person1;
  h *ptr_human1,human1;
  ptr_human1=&human1;
  printf("Enter name: ");
  scanf("%s", person1.name);
  printf("Enter age: ");
  scanf("%d", &person1.age);
  printf("Enter address: ");
  scanf("%s", person1.address);
  printf("Enter email: ");
  scanf("%s", person1.email);
  printf("Enter weight: ");
  scanf("%f", &person1.weight);
  printf("Enter phone number: ");
  scanf("%d", &person1.phoneNumber);
  strcpy(ptr_human1->address, ptr_person1->address);
  ptr_human1->phoneNumber=ptr_person1->phoneNumber;

  printf("enter human1 remaining details: ");
  printf("Enter name: ");
  scanf("%s", human1.name);
  printf("Enter age: ");
  scanf("%d", &human1.age);
  printf("Enter email: ");
  scanf("%s", human1.email);
  printf("Enter weight: ");
  scanf("%f", &human1.weight);

  printf("human1 details: ");
  printf("name:%s, age:%d, address:%s, email:%s, weight:%f, phone number:%d", human1.name, human1.age, human1.address, human1.email, human1.weight, human1.phoneNumber);

  return 0;
}