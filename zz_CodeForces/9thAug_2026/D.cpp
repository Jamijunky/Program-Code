#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll T, const vector<ll> &a, int n)
{
    priority_queue<ll> pq;
    for (int i = 0; i < n; ++i)
    {
        pq.push(a[i]);
    }

    for (ll t = T - 1; t >= 0; --t)
    {
        if (pq.empty())
        {
            break;
        }

        ll u = pq.top();
        pq.pop();

        if (t >= 30)
        {
            continue;
        }

        ll power = (1LL << t);
        if (u > power)
        {
            pq.push(u - power);
        }
    }

    return pq.empty();
}

void Solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    ll low = n, high = n + 35;
    ll ans = high;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, a, n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        Solve();
    }

    return 0;
}