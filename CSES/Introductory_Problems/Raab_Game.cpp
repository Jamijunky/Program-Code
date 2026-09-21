#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if ((a == 0 && b == 0) || (a > 0 && b > 0 && a + b <= n))
        {
            cout << "YES\n";

            int d = n - a - b;

            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << '\n';

            for (int i = 1; i <= d; i++)
                cout << i << " ";

            for (int i = d + a + 1; i <= n; i++)
                cout << i << " ";

            for (int i = d + 1; i <= d + a; i++)
                cout << i << " ";

            cout << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
}