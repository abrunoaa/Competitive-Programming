#include <bits/stdc++.h>
using namespace std;

typedef int Int;

#define int long long
#define maxn 100010
#define fst first
#define snd second

typedef pair<int,int> ii;

int N;
int h[maxn], pai[maxn][20] = {}, cost[maxn][20] = {};
vector<ii> g[maxn];

void dfsLca(int u, int p)
{
  for (int i = 0; i < (int)g[u].size(); ++i)
  {
    int v = g[u][i].fst;
    int c = g[u][i].snd;
    if (v != p)
    {
      h[v] = h[u] + 1;
      pai[v][0] = u;
      cost[v][0] = c;
      dfsLca(v, u);
    }
  }
}

void buildLca()
{
  h[0] = 0;
  dfsLca(0, -1);
  for (int i = 1; i < 20; ++i)
    for (int u = 0; u < N; ++u)
    {
      int v = pai[u][i - 1];
      pai[u][i] = pai[v][i - 1];
      cost[u][i] = cost[u][i - 1] + cost[v][i - 1];
    }
}

int lca(int u, int v)
{
  if (h[u] < h[v]) swap(u, v);

  int c = 0;

  if (h[u] != h[v])
    for (int i = 20, d = h[u] - h[v]; i--; )
      if (d & (1 << i))
      {
        c += cost[u][i];
        u = pai[u][i];
      }

  if (u == v) return c;

  for (int i = 20; i--; )
    if (pai[u][i] != pai[v][i])
    {
      c += cost[u][i] + cost[v][i];
      u = pai[u][i];
      v = pai[v][i];
    }

  return c + cost[u][0] + cost[v][0];
}

Int main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> N && N)
  {
    for (int i = 0; i < N; ++i) g[i].clear();

    for (int i = 1, a, l; i < N; ++i)
    {
      cin >> a >> l;
      g[i].push_back(ii(a, l));
      g[a].push_back(ii(i, l));
    }

    buildLca();

    int Q;
    cin >> Q;
    for (int i = 0, s, t; i < Q; ++i)
    {
      cin >> s >> t;
      if (i) cout << ' ';
      cout << lca(s, t);
    }
    cout << '\n';
  }

  return 0;
}
