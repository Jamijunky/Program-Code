#include <stdio.h>

struct branch
{
  char address[30];
  char email[30];
  char team_name[30];
  long long contact_number;

} branch_info;
struct id_number
{
  char name[20];
  char gender;
  char designation[20];
  struct branch branch_info;

} id_number1;
int main()
{
  printf("Enter Name:");
  scanf("%s", id_number1.name);
  printf("Enter Gender(M/F):");
  scanf("%c", &id_number1.gender);
  printf("Enter Designation:");
  scanf("%s", id_number1.designation);
  printf("Enter Branch address:");
  scanf("%s", id_number1.branch_info.address);
  printf("Enter Branch Mail:");
  scanf("%s", id_number1.branch_info.email);
  printf("Enter Team Name:");
  scanf("%s", id_number1.branch_info.team_name);
  printf("Enter Contact Number:");
  scanf("%lld", &id_number1.branch_info.contact_number);

  return 0;
}