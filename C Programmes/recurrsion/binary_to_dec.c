#include<stdio.h>
int binary_to_dec(int ,int ,int );
int main()
{
int binary, decimal;
printf("binary number is");
scanf("%d",&binary);
decimal=binary_to_dec(binary,1,0);
printf("decimal of %d is %d",binary,decimal);
}

int binary_to_dec(int b,int c,int t)
{ if(b>0)
  {t+=(b%10)*c;
  return binary_to_dec(b/10,c*2,t);}
else return t;
}

