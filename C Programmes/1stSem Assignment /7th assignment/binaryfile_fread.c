#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[50];
  unsigned int id;
  float average;
} Student;

int main()
{
  FILE *fp;
  Student students[100];
  size_t n_students = 0;
  fp = fopen("students.bin", "rb");
  if (fp == NULL)
  {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  while (fread(&students[n_students], sizeof(Student), 1, fp) == 1)
  {
    n_students++;
  }

  fclose(fp);

  for (size_t i = 0; i < n_students; i++)
  {
    printf("Name: %s, ID: %u, Average: %.2f\n", students[i].name, students[i].id, students[i].average);
  }

  return EXIT_SUCCESS;
}