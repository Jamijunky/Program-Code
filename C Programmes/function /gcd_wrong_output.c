#include <stdio.h>

int gcd(int n1 , int n2)
{
    int r=(n1>n2)?(n1%n2):(n2%n1);
    printf("%d\n",n1);
    while (r>=1)
    {
        if (n1 >= n2)
        {
            r = n1 % n2 ;
            n1 = n2 ;
            n2 = r ;
            return r;
        }
        else
        {
            r = n2 % n1 ;
            n2 = n1 ;
            n1 = r ;
            return r;
          
        } 
    } 
}
int main()
{ 
    int num1 , num2 ;
    printf("Enter two numbers :\n");
    scanf("%d%d",&num1 , &num2);
    printf("%d",gcd(num1,num2));
    return 0;
}