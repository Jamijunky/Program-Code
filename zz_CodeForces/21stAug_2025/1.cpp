#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        string a, b, c;
        cin >> a;
        cin >> m;
        cin >> b;
        cin >> c;

        for (int i = 0; i < (int)b.length(); i++) {
            if (c[i] == 'D') { 
                a.push_back(b[i]);
            } else { 
                a = b[i] + a; 
            }
        }
        cout << a << endl;
    }
    return 0;
}
