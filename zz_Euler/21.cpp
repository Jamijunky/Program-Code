#include <iostream>
using namespace std;

int sumOfDivisors(int n) {
    int sum = 1; // 1 is always a divisor
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i; // paired divisor
        }
    }
    return (n == 1) ? 0 : sum;
}

int main() {
    int totalSum = 0;
    for (int i = 2; i <= 10000; i++) {
        int sum1 = sumOfDivisors(i);
        if (sum1 != i && sum1 <= 10000) { 
            int sum2 = sumOfDivisors(sum1);
            if (sum2 == i) totalSum += i;
        }
    }
    cout << totalSum;
    return 0;
}
