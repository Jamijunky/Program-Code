#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int next[26];
    int fail;

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

    for (int i = 0; i < k; i++) {
        string t;
        cin >> t;

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

    for (int i = 0; i < 26; i++) {
        if (trie[0].next[i] == -1) {
            trie[0].next[i] = 0;
        } else {
            int child = trie[0].next[i];
            trie[child].fail = 0;
            q.push(child);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        order.push_back(v);

        for (int i = 0; i < 26; i++) {
            if (trie[v].next[i] == -1) {
                trie[v].next[i] =
                    trie[trie[v].fail].next[i];
            } else {
                int u = trie[v].next[i];

                trie[u].fail =
                    trie[trie[v].fail].next[i];

                q.push(u);
            }
        }
    }

    vector<int> cnt(trie.size(), 0);

    int node = 0;

    for (char ch : s) {
        int c = ch - 'a';

        node = trie[node].next[c];
        cnt[node]++;
    }

    reverse(order.begin(), order.end());

    for (int v : order) {
        cnt[trie[v].fail] += cnt[v];
    }

    for (int i = 0; i < k; i++) {
        cout << cnt[patternNode[i]] << '\n';
    }

    return 0;
}