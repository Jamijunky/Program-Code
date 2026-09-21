#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    for (char c : S) {
        if (c == 'A')
            cout << c;
        else
            cout << '.';
    }
    cout << '\n';

    return 0;
}