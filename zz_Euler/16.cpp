#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> num = {1}; // start with 2^0 = 1

    for (int i = 0; i < 1000; i++) {
        int carry = 0;
        for (int j = 0; j < num.size(); j++) {
            int prod = num[j] * 2 + carry;
            num[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            num.push_back(carry % 10);
            carry /= 10;
        }
    }

    int sum = 0;
    for (int d : num) sum += d;

    cout << "Sum of digits of 2^1000 is: " << sum << endl;
    return 0;
}
