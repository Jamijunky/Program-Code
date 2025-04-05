#include <stdio.h>

int factorial(int a);
void multi_table(int a);
int primeornot (int a);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Factorial
    int fact = factorial(num);
    if (fact != -1) {
        printf("Factorial of %d is %d\n", num, fact);
    } else {
        printf("Factorial is not defined for negative numbers.\n");
    }

    // Multiplication Table
    multi_table(num);

    // Prime Check
    primeornot(num);
    
    return 0;
}

int factorial(int num) {
    if (num < 0) return -1; // Factorial is not defined for negative numbers
    if (num == 0) return 1; // Base case for factorial

    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

void multi_table(int num) {
    if (num % 3 == 0) {
        printf("multiplication Table of %d:\n", num);
        for (int i = 1; i <= 10; i++) {
            printf("%d * %d = %d\n", num, i, num * i);
        }
    } else {
        printf("%d is not a multiple of 3, so no Multiplication table will be printed.\n", num);
    }
}

 int primeornot(int num) {
    if (num < 2) {
        printf("%d is not a prime number.\n", num);
        return 0 ;
    }

    for (int i = 2; i * i <= num; i++) { // Check up to the square root
        if (num % i == 0) {
            printf("%d is not a prime number.\n", num);
            return 0;
        }
    }
    printf("%d is a prime number.\n", num);
    return 0;
}
