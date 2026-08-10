#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int val;
    int type;  
};

long long solve_cap(int K_cap, int L_cap, const vector<Element>& sorted_elems) {
    long long sum = 0;
    int countA = 0;
    int countB = 0;
    int countTotal = 0;
    int maxTotal = K_cap + L_cap;

    for (const auto& elem : sorted_elems) {
        if (countTotal >= maxTotal) break;

        if (elem.type == 1) { 
            if (countA + 1 <= K_cap) {
                countA++;
                countTotal++;
                sum += elem.val;
            }
        } else if (elem.type == 2) {  
            if (countB + 1 <= L_cap) {
                countB++;
                countTotal++;
                sum += elem.val;
            }
        } else {  
            countTotal++;
            sum += elem.val;
        }
    }
    return sum;
}

void solve() {
    int n, m, x, y;
    if (!(cin >> n >> m >> x >> y)) return;

    vector<int> a(x);
    for (int i = 0; i < x; ++i) cin >> a[i];

    vector<int> b(y);
    for (int i = 0; i < y; ++i) cin >> b[i];

    vector<Element> elems;
    int i = 0, j = 0;
    while (i < x || j < y) {
        if (i < x && j < y) {
            if (a[i] == b[j]) {
                elems.push_back({a[i], 3});
                i++;
                j++;
            } else if (a[i] < b[j]) {
                elems.push_back({a[i], 1});
                i++;
            } else {
                elems.push_back({b[j], 2});
                j++;
            }
        } else if (i < x) {
            elems.push_back({a[i], 1});
            i++;
        } else {
            elems.push_back({b[j], 2});
            j++;
        }
    }

    sort(elems.begin(), elems.end(), [](const Element& e1, const Element& e2) {
        return e1.val > e2.val;
    });

    int K = min(x, n);
    int L = min(y, m);

    if (K == n && L == m) {
        long long ans1 = solve_cap(n - 1, m, elems);
        long long ans2 = solve_cap(n, m - 1, elems);
        cout << max(ans1, ans2) << "\n";
    } else {
        cout << solve_cap(K, L, elems) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}