#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<tuple<long long, long long, int>> pos(n);

    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        pos[i] = {x, y, i};
    }

    vector<int> contains(n, 0);
    vector<int> contained(n, 0);

    sort(pos.begin(), pos.end(), [](auto &a, auto &b)
    {
        if (get<0>(a) != get<0>(b))
            return get<0>(a) < get<0>(b);

        return get<1>(a) > get<1>(b);
    });

    long long maxRight = 0;

    for (int i = 0; i < n; i++)
    {
        if (maxRight >= get<1>(pos[i]))
            contained[get<2>(pos[i])] = 1;

        maxRight = max(maxRight, get<1>(pos[i]));
    }

    long long minRight = LLONG_MAX;

    for (int i = n - 1; i >= 0; i--)
    {
        if (minRight <= get<1>(pos[i]))
            contains[get<2>(pos[i])] = 1;

        minRight = min(minRight, get<1>(pos[i]));
    }

    for (int x : contains)
        cout << x << " ";

    cout << '\n';

    for (int x : contained)
        cout << x << " ";

    return 0;
}