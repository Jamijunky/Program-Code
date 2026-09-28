#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// KMP: matched string → longest suffix that is also PREFIX OF ONE PATTERN
// Aho-Corasick: matched Trie path → longest suffix that is also A PATH IN THE TRIE

struct Node {
    // next[c] = next Trie node using character c
    //
    // Initially:
    // -1 means there is no actual Trie edge.
    //
    // After building Aho-Corasick:
    // every next[c] becomes a valid automaton transition.
    int next[26];

    // Failure link:
    // longest proper suffix of this node's string
    // which is also a Trie path.
    int fail;

    Node() {
        fill(next, next + 26, -1);
        fail = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ------------------------------------------------------------
    // INPUT
    // ------------------------------------------------------------

    string text;
    cin >> text;

    int k;
    cin >> k;

    // Node 0 = root
    vector<Node> trie(1);

    // patternNode[i] = Trie node representing the i-th pattern
    vector<int> patternNode(k);


    // ------------------------------------------------------------
    // 1. BUILD TRIE
    // ------------------------------------------------------------

    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;

        int node = 0;

        for (char ch : s) {
            int c = ch - 'a';

            // If this character doesn't have a Trie edge,
            // create a new node.
            if (trie[node].next[c] == -1) {
                trie[node].next[c] = trie.size();
                trie.push_back(Node());
            }

            // Move to the node representing the string
            // matched so far.
            node = trie[node].next[c];
        }

        // Remember where this pattern ends.
        patternNode[i] = node;
    }


    // ------------------------------------------------------------
    // 2. BUILD FAILURE LINKS + AUTOMATON
    // ------------------------------------------------------------

    queue<int> q;

    // We MUST save the actual BFS order.
    //
    // Later, for failure propagation, we need to process
    // deeper states before their failure states.
    vector<int> order;

    // Handle root's children first.
    for (int c = 0; c < 26; c++) {

        if (trie[0].next[c] == -1) {
            // If a character doesn't start any pattern,
            // seeing it from root keeps us at root.
            trie[0].next[c] = 0;
        }
        else {
            // Every direct child of root has failure = root.
            int child = trie[0].next[c];
            trie[child].fail = 0;

            q.push(child);
        }
    }


    // BFS through the Trie.
    while (!q.empty()) {

        int v = q.front();
        q.pop();

        // Save the actual BFS order.
        order.push_back(v);

        for (int c = 0; c < 26; c++) {

            // ----------------------------------------------------
            // NO ACTUAL TRIE EDGE
            // ----------------------------------------------------

            if (trie[v].next[c] == -1) {

                // We cannot continue from v using c.
                //
                // Fall back to fail[v] and try the SAME character.
                //
                // Because fail[v] has already been processed,
                // its transition is already known.
                trie[v].next[c] =
                    trie[trie[v].fail].next[c];
            }

            // ----------------------------------------------------
            // ACTUAL TRIE EDGE
            // ----------------------------------------------------

            else {

                int u = trie[v].next[c];

                // Calculate failure of u.
                //
                // We first fall back from v,
                // then try the same character c.
                trie[u].fail =
                    trie[trie[v].fail].next[c];

                // u will be processed later by BFS.
                q.push(u);
            }
        }
    }


    // ------------------------------------------------------------
    // 3. SCAN TEXT
    // ------------------------------------------------------------

    // seen[v] = true means the automaton reached node v
    // somewhere while scanning the text.
    vector<bool> seen(trie.size(), false);

    int node = 0;

    for (char ch : text) {

        int c = ch - 'a';

        // Move using the already-computed Aho-Corasick transition.
        //
        // All failure fallback work has already been built
        // into trie[node].next[c].
        node = trie[node].next[c];

        seen[node] = true;
    }


    // ------------------------------------------------------------
    // 4. PROPAGATE THROUGH FAILURE LINKS
    // ------------------------------------------------------------

    // Example:
    //
    // BAB
    //  |
    // fail
    //  ↓
    // AB
    //
    // If BAB was seen, then AB was also seen.
    //
    // We therefore propagate:
    //
    // seen[v] -> seen[fail[v]]
    //
    // IMPORTANT:
    // We process the BFS order backwards so that deeper nodes
    // are propagated BEFORE their failure parents.
    reverse(order.begin(), order.end());

    for (int v : order) {

        seen[trie[v].fail] =
            seen[trie[v].fail] || seen[v];
    }


    // ------------------------------------------------------------
    // 5. ANSWER
    // ------------------------------------------------------------

    for (int i = 0; i < k; i++) {

        // patternNode[i] is the node representing this pattern.
        //
        // If that node was seen, the pattern occurs in the text.
        cout << (seen[patternNode[i]] ? "YES\n" : "NO\n");
    }

    return 0;
}