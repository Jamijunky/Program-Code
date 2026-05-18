#include <iostream>
#include <stack>
using namespace std;

int main() {
    string input;
    cin >> input;

    stack<char> st;
    st.push('$');
    st.push('E');

    int i = 0;

    while (!st.empty()) {
        char top = st.top();

        if (top == input[i]) {
            st.pop();
            i++;
        } else if (top == 'E') {
            st.pop();
            st.push('a');
        } else {
            cout << "Rejected";
            return 0;
        }
    }

    if (input[i] == '\0')
        cout << "Accepted";
    else
        cout << "Rejected";
}