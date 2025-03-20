#include <iostream>
#include <cctype>
using namespace std;

// Function to decode the hidden message
string decodeMessage(const string& coded) {
    string decoded = "";

    for (char ch : coded) {
        if (isalpha(ch)) {
            if (islower(ch)) {
                decoded += 'z' - (ch - 'a');  // Reverse lowercase letters
            } else {
                decoded += 'Z' - (ch - 'A');  // Reverse uppercase letters
            }
        } else if (isdigit(ch)) {
            decoded += '9' - (ch - '0');  // Reverse digits
        } else {
            decoded += ch;  // Keep punctuation and spaces unchanged
        }
    }

    return decoded;
}

int main() {
    string codedMessage;
    cout << "Enter the coded message: ";
    getline(cin, codedMessage);

    string decodedMessage = decodeMessage(codedMessage);
    cout << "Decoded Message: " << decodedMessage << endl;

    return 0;
}
