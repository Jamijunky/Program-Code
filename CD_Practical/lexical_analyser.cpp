#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    for (char c : s) {
        if (isalpha(c))
            cout << c << " : Identifier\n";
        else if (isdigit(c))
            cout << c << " : Digit\n";
        else if (ispunct(c))
            cout << c << " : Operator/Symbol\n";
    }
}