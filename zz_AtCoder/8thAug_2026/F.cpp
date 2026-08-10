#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long power(long long base, long long exp)
{
  long long res = 1;
  base %= MOD;
  while (exp > 0)
  {
    if (exp % 2 == 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp /= 2;
  }
  return res;
}
long long modInverse(long long n)
{
  return power(n, MOD - 2);
}

const int MAXN = 200005;
long long fact[MAXN];
long long invFact[MAXN];

void precompute()
{
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i < MAXN; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
  for (int i = MAXN - 2; i >= 1; i--)
  {
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
  }
}

void Solve()
{
  int N, M;
  if (!(cin >> N >> M))
    return;

  string S;
  cin >> S;

  vector<vector<int>> adj(N + 1);
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(N + 1, false);
  long long total_ans = 1;

  bool can_flip_parity_invisibly = false;

  for (int i = 1; i <= N; i++)
  {
    if (!visited[i])
    {
      vector<int> component;
      queue<int> q;

      q.push(i);
      visited[i] = true;

      while (!q.empty())
      {
        int u = q.front();
        q.pop();
        component.push_back(u);

        for (int v : adj[u])
        {
          if (!visited[v])
          {
            visited[v] = true;
            q.push(v);
          }
        }
      }

      int char_counts[26] = {0};
      for (int u : component)
      {
        int char_idx = S[u - 1] - 'a';
        char_counts[char_idx]++;
        if (char_counts[char_idx] > 1)
        {
          can_flip_parity_invisibly = true;
        }
      }

      long long comp_permutations = fact[component.size()];
      for (int c = 0; c < 26; c++)
      {
        if (char_counts[c] > 0)
        {
          comp_permutations = (comp_permutations * invFact[char_counts[c]]) % MOD;
        }
      }

      total_ans = (total_ans * comp_permutations) % MOD;
    }
  }
  if (!can_flip_parity_invisibly)
  {
    total_ans = (total_ans * modInverse(2)) % MOD;
  }

  cout << total_ans << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  precompute();

  Solve();

  return 0;
}