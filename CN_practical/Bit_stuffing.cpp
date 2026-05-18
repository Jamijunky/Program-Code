#include <iostream>
#include <string>
using namespace std;

int main() {
    string data;
    cin >> data;

    string stuffed = "";
    int count = 0;

    for (char c : data) {
        if (c == '1') {
            count++;
            stuffed += c;
            if (count == 5) {
                stuffed += '0';
                count = 0;
            }
        } else {
            stuffed += c;
            count = 0;
        }
    }

    cout << stuffed;
    return 0;
}