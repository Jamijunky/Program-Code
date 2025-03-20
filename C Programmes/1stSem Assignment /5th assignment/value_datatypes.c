#include<stdio.h>
int main()
{
  int ih=1;
  int *i=&ih;
  float fh=1.1;
  float *f=&fh;
  char ch='a';
  char *c=&ch;
  printf("address of int variable is %p\n", i);
  printf("address of float variable is %p\n", f);
  printf("address of char variable is %p\n", c);
  printf("value of int variable is %d\n", *i);
  printf("value of float variable is %f\n", *f);
  printf("value of char variable is %c\n", *c);
  
  return 0;

}