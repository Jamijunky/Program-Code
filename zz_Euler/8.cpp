#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cout << "Enter the 1000-digit number: ";
    cin >> num;

    long long int maxvalue = 0;

    for (int i = 0; i <= num.size() - 13; i++) {
        long long int product = 1;
        for (int j = 0; j < 13; j++) {
            product *= num[i + j] - '0';
        }
        maxvalue = max(maxvalue, product);
    }

    cout << "Greatest product of 13 consecutive digits: " << maxvalue << endl;
    return 0;
}
