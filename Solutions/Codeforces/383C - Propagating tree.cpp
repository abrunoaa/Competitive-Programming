#include <bits/stdc++.h>
using namespace std;

#define maxn 200010
#define pb push_back

bool h[maxn];
int n, m, a[maxn];
int cnt = 1, in[maxn], out[maxn], bit[maxn][2] = {};
vector<int> g[maxn];

void update(int x, int y, int a)
{ for (; x <= n; x += x & -x) bit[x][y] += a; }

int query(int x, int y)
{
  int s = 0;
  for (; x; x -= x & -x) s += bit[x][y];
  return s;
}

void build(int u, int p)
{
  in[u] = cnt;
  update(in[u], h[u], a[u]);
  update(in[u] + 1, h[u], -a[u]);
  for (int i = 0; i < (int)g[u].size(); ++i)
  {
    int v = g[u][i];
    if (v != p)
    {
      h[v] = h[u] ^ 1;
      ++cnt;
      build(v, u);
    }
  }
  out[u] = cnt;
}

int main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 0, u, v; i < n - 1; ++i)
  {
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }

  h[1] = 0;
  build(1, 0);

  while (m--)
  {
    int op;
    cin >> op;

    if (op == 1)
    {
      int x, v;
      cin >> x >> v;
      update(in[x], h[x], v);
      update(out[x] + 1, h[x], -v);
      update(in[x], h[x] ^ 1, -v);
      update(out[x] + 1, h[x] ^ 1, v);
    }
    else
    {
      int x;
      cin >> x;
      cout << query(in[x], h[x]) << '\n';
    }
  }

  return 0;
}
