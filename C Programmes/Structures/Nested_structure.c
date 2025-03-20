#include <stdio.h>
struct Address
{
  char Street[50];
  char City[50];
  char State[50];
  int Zip_Code;
};

struct Serial_No
{
  char Name[20];
  int Age;
  char Gender[1];
  int phone_Number;
  char Email[50];
  struct Address add;
};

int main()
{
  int n;
  printf("Enter the number of people: ");
  scanf("%d", &n);
  struct Serial_No person[n];

  printf("Enter the details of people\n");
  for (int i = 0; i < n; i++)
  {
    printf("Enter Name: ");
    scanf("%s", person[i].Name);
    printf("Enter Age: ");
    scanf("%d", &person[i].Age);
    printf("Enter Gender (M/F): ");
    scanf("%s", person[i].Gender);
    printf("Enter Phone Number: ");
    scanf("%d", &person[i].phone_Number);
    printf("Enter Email: ");
    scanf("%s", person[i].Email);
    printf("Enter Address (Street, City, State, Zip Code):\n");
    scanf("%s %s %s %d", person[i].add.Street, person[i].add.City, person[i].add.State, &person[i].add.Zip_Code);
    printf("\n");
  }
  printf("Name\tAge\tGender(M/F)\tPhone Number\tEmail\t\tAddress\n");
  for (int i = 0; i < n; i++)
  {
    printf("%s\t%d\t%s\t\t%d\t\t%s\t\t%s, %s %s %d\n", person[i].Name, person[i].Age, person[i].Gender, person[i].phone_Number, person[i].Email, person[i].add.Street, person[i].add.City, person[i].add.State, person[i].add.Zip_Code);
  }

  return 0;
}