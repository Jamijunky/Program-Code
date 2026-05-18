#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    string s;
    cin >> s;
    stack<char> st;

    for (char c : s) {
        if (isalnum(c))
            cout << c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}