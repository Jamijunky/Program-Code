#include <iostream>
#include <regex>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    regex pattern("(int|float|char|double)\\s+[a-zA-Z_][a-zA-Z0-9_]*\\s*;");
    if (regex_match(s, pattern))
        cout << "Valid Declarative Statement";
    else
        cout << "Invalid Declarative Statement";
}