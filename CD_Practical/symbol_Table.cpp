#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> symbolTable;

    symbolTable["x"] = "int";
    symbolTable["y"] = "float";
    symbolTable["z"] = "char";

    for (auto &p : symbolTable)
        cout << p.first << " : " << p.second << endl;
}