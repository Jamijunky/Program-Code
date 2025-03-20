#include<stdio.h>
struct student
{
    char name[50];
    int roll_no;
    float marks;
};
int main()
{
   int n;
   printf("Enter the number of students: ");
   scanf("%d", &n);
   struct student students[n];

   printf("Enter the details of students:\n");
   for(int i=0; i<n; i++)
   {
       printf("Enter name: ");
       scanf("%s", students[i].name);
       printf("Enter roll number: ");
       scanf("%d", &students[i].roll_no);
       printf("Enter marks: ");
       scanf("%f", &students[i].marks);
       printf("\n");
       }
       printf("Name\tRoll Number\tMark\n");
       for(int i=0; i<n; i++)
       {
           printf("%s\t   %d\t\t%f\n", students[i].name, students[i].roll_no, students[i].marks);
       }  
       return 0;
}