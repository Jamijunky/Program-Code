#include <iostream>
using namespace std;

int main() {
    string s, input = "";
    while (getline(cin, s))
        input += s;

    size_t start = input.find("/*");
    size_t end = input.find("*/");

    if (start != string::npos && end == string::npos)
        cout << "Unterminated comment detected";
    else
        cout << "Comments properly terminated";
}