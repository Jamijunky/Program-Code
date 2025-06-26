#include <iostream>
#include <string>

using namespace std;

int computeStrength(const string &s) {
    int strength = 0;
    int count = 1;

    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1])
            count++;
        else {
            strength += min(2, count);
            count = 1;
        }
    }
    strength += min(2, count);
    return strength;
}

int main() {
    string s = "aabbcc";
    cout << "Strength: " << computeStrength(s) << endl;
    return 0;
}
