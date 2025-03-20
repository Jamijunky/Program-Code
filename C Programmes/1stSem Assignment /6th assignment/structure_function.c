#include <stdio.h>

struct Student
{
  char name[50];
  int age;
};

void display(struct Student s);

int main()
{
  struct Student s1 = {"Alice", 20};
  display(s1);
  return 0;
}

void display(struct Student s)
{
  printf("Name: %s, Age: %d\n", s.name, s.age);
}