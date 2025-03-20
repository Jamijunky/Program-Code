#include <stdio.h>
#include <string.h>

struct Student
{
  char name[50];
  int age;
};

void swap(struct Student *a, struct Student *b)
{
  struct Student temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main()
{
  struct Student student1 = {"Alice", 20};
  struct Student student2 = {"Bob", 22};

  printf("Before swap:\n");
  printf("Student 1: %s, Age: %d\n", student1.name, student1.age);
  printf("Student 2: %s, Age: %d\n", student2.name, student2.age);

  swap(&student1, &student2);

  printf("After swap:\n");
  printf("Student 1: %s, Age: %d\n", student1.name, student1.age);
  printf("Student 2: %s, Age: %d\n", student2.name, student2.age);

  return 0;
}