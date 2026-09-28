#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int fail;
    int next[26];

    Node() {
        fill(next, next + 26, -1);
        fail = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<Node> trie(1);
    vector<int> patternNode(k);
    vector<int> patternLength(k);

    for (int i = 0; i < k; i++) {
        string t;
        cin >> t;

        patternLength[i] = t.size();

        int node = 0;

        for (char ch : t) {
            int c = ch - 'a';

            if (trie[node].next[c] == -1) {
                trie[node].next[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].next[c];
        }

        patternNode[i] = node;
    }

    queue<int> q;
    vector<int> order;

    for (int c = 0; c < 26; c++) {
        if (trie[0].next[c] == -1) {
            trie[0].next[c] = 0;
        } else {
            int child = trie[0].next[c];
            trie[child].fail = 0;
            q.push(child);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        order.push_back(v);

        for (int c = 0; c < 26; c++) {
            if (trie[v].next[c] == -1) {
                trie[v].next[c] =
                    trie[trie[v].fail].next[c];
            } else {
                int u = trie[v].next[c];

                trie[u].fail =
                    trie[trie[v].fail].next[c];

                q.push(u);
            }
        }
    }

    const int INF = 1e9;
    vector<int> first(trie.size(), INF);

    int node = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        int c = s[i] - 'a';

        node = trie[node].next[c];

        first[node] = min(first[node], i + 1);
    }

    reverse(order.begin(), order.end());

    for (int v : order) {
        first[trie[v].fail] =
            min(first[trie[v].fail], first[v]);
    }

    for (int i = 0; i < k; i++) {
        if (first[patternNode[i]] == INF) {
            cout << -1 << '\n';
        } else {
            cout << first[patternNode[i]]
                 - patternLength[i] + 1
                 << '\n';
        }
    }

    return 0;
}