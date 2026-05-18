#include <iostream>
#include <regex>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    regex pattern("^[0-9]+([+\\-*/][0-9]+)*$");
    if (regex_match(s, pattern))
        cout << "Valid Arithmetic Expression";
    else
        cout << "Invalid Arithmetic Expression";
}