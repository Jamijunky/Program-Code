#include <iostream>
#include <string>
using namespace std;

int main() {
    string data;
    cin >> data;

    char flag = 'F';
    char esc = 'E';

    string stuffed = "";
    stuffed += flag;

    for (char c : data) {
        if (c == flag || c == esc) {
            stuffed += esc;
        }
        stuffed += c;
    }

    stuffed += flag;

    cout << stuffed;
    return 0;
}