#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    unordered_map<long long, int> last_seen;
    last_seen.reserve(N * 2 + 5);
    last_seen.max_load_factor(0.7);

    long long pref = 0;
    int version = 0;
    last_seen[0] = 0;

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        long long a;
        cin >> a;
        pref = (pref + a) % K;

        auto it = last_seen.find(pref);
        if (it != last_seen.end() && it->second == version)
        {
            ++ans;
            ++version;
            last_seen[pref] = version;
        }
        else
        {
            last_seen[pref] = version;
        }
    }

    cout << ans << '\n';
    return 0;
}