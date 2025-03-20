#include<stdio.h>
int dec_to_binary(int decimal);
int main()
{
  int decimal,binary;
printf("decimal no is");
scanf("%d",&decimal);
binary=dec_to_binary(decimal);
printf("binary of %d is %d",decimal,binary);}

int dec_to_binary(int b)
{if (b==0)
return 0;

  int binary=b%2 + 10*(dec_to_binary(
    b/2));
  return binary;
}