#include <iostream>
using namespace std;

// Function to reverse a number
int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    return num == reverseNumber(num);
}

// Function to check if a number is Echolandic
void checkEcholandic(int num) {
    int reversed = reverseNumber(num);
    int sum = num + reversed;

    if (isPalindrome(sum)) {
        cout << "Echolandic Number: " << sum << endl;
    } else {
        cout << "Not an Echolandic Number" << endl;
    }
}

int main() {
    int num;
    cout<<"Enter number: ";
    cin >> num; // Read input number
    checkEcholandic(num);
    return 0;
}
