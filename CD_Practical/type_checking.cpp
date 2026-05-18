#include <iostream>
using namespace std;

int main() {
    string varType, valueType;
    cin >> varType >> valueType;

    if (varType == valueType)
        cout << "Type Compatible";
    else
        cout << "Type Mismatch";
}