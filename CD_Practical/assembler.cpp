#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> defined = {"START", "LOOP"};
    set<string> used = {"START", "END"};

    for (auto u : used)
        if (defined.find(u) == defined.end())
            cout << "Undefined symbol: " << u << endl;

    for (auto d : defined)
        if (used.find(d) == used.end())
            cout << "Unused symbol: " << d << endl;
}