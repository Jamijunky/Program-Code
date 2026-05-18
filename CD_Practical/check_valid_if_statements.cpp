#include <iostream>
#include <regex>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    regex pattern("^if\\s*\\(.*\\)\\s*\\{.*\\}$");
    if (regex_match(s, pattern))
        cout << "Valid If Statement";
    else
        cout << "Invalid If Statement";
}