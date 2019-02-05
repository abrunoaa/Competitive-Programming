#include <bits/stdc++.h>
using namespace std;

#define maxn 20001
#define int long long

int N, T, CS = 0;
vector<int> g[maxn], child[maxn];

int dfs(int p, int k)
{
  // assert(k < (int)child[p].size());
  // assert(k < (int)g[p].size());

  int &c = child[p][k];
  if (c != -1) return c;

  c = 0;
  int u = g[p][k];
  for (int i = 0; i < (int)g[u].size(); ++i)
    if (g[u][i] != p)
      c += dfs(u, i);

  return ++c;
}

int32_t main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> T;
  while (T--)
  {
    cin >> N;
    for (int i = 0; i < N; ++i) g[i].clear(), child[i].clear();
    for (int i = 0, a, b; i < N - 1; ++i)
    {
      cin >> a >> b, --a, --b;
      g[a].push_back(b);
      g[b].push_back(a);
      child[a].push_back(-1);
      child[b].push_back(-1);
    }

    int busiest = 0;
    for (int i = 0; i < N; ++i)
      if (g[i].size() > 1)
      {
        int busyness = 0;
        for (int j = 0; j < (int)g[i].size(); ++j)
        {
          int f = dfs(i, j);
          int g = N - f - 1;
          busyness += f * g;
        }
        busiest = max(busiest, busyness);
      }

    cout << "Case #" << ++CS << ": " << busiest / 2 << '\n';
  }

  return 0;
}
