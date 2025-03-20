#include <stdio.h>
#include <math.h>

float fact(int t ){
    int f = 1 ;
    for (int i = 1; i <= t; i++)
    {
         f = f*i ;
    }
    return f ;
}

float series(float num){
    float sum = 0 ;
    for (int i = 0; i <10  ; i++)
    { int t=2*i+1;
    float term=pow(num,t)/fact(t);
        if (i%2==0){
        sum += term ;
        }
        else{
        sum -= term;
        }
        
    }
    return sum ;
    
}

int main()
{ 
    float num ;
    printf("Enter the number:");
    scanf("%f",&num);
    printf("%.6f",series(num));
    return 0;
}