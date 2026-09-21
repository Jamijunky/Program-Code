#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> val(n);

    for (int i = 0; i < n; i++)
    {
        cin >> val[i].first;
        val[i].second = i + 1;
    }

    sort(val.begin(), val.end());

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            long long sum = val[i].first + val[j].first + val[k].first;

            if (sum == x)
            {
                cout << val[i].second << " "
                     << val[j].second << " "
                     << val[k].second;
                return 0;
            }
            else if (sum < x)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}