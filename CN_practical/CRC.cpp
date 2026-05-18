#include <iostream>
#include <string>
using namespace std;

string xorOperation(string a, string b) {
    string result = "";

    for (int i = 1; i < b.length(); i++) {
        if (a[i] == b[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);

    while (pick < dividend.length()) {
        if (tmp[0] == '1')
            tmp = xorOperation(divisor, tmp) + dividend[pick];
        else
            tmp = xorOperation(string(divisor.length(), '0'), tmp) + dividend[pick];

        pick++;
    }

    if (tmp[0] == '1')
        tmp = xorOperation(divisor, tmp);
    else
        tmp = xorOperation(string(divisor.length(), '0'), tmp);

    return tmp;
}

int main() {
    string data, generator;

    cout << "Enter data bits: ";
    cin >> data;

    cout << "Enter generator polynomial: ";
    cin >> generator;

    int m = generator.length();

    string appended = data + string(m - 1, '0');

    string remainder = mod2div(appended, generator);

    string transmitted = data + remainder;

    cout << "\nCRC Remainder: " << remainder;
    cout << "\nTransmitted Data: " << transmitted;

    // Receiver Side
    string received;
    cout << "\n\nEnter received data: ";
    cin >> received;

    string check = mod2div(received, generator);

    bool error = false;
    for (char c : check) {
        if (c == '1') {
            error = true;
            break;
        }
    }

    if (error)
        cout << "\nError detected in received data.";
    else
        cout << "\nNo error detected.";

    return 0;
}