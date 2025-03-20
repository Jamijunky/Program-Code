#include <stdio.h>

int main(void) {
    int c,num;
    printf("Enter the number");
    scanf("%d",&num);
    up:
    c =num % 10;
    num=(num-c)/10;
    if (c>0)
    {printf("%d",c);
    goto up;}
return 0;
}
