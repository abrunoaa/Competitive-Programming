#include <bits/stdc++.h>
using namespace std;

#define maxn 105
#define maxv 55
#define inf 0x3f3f3f3f
#define pb push_back

int n, m, k;
bool vis[maxn], terra[maxn][maxn];
int p[maxv], flow[maxv][maxv];
vector<int> g[maxv];

bool bfs(int so, int si)
{
  memset(vis, 0, sizeof vis);

  queue<int> q;
  q.push(so);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int i = 0; i < (int)g[u].size(); ++i)
    {
      int v = g[u][i];
      if (!vis[v] && flow[u][v] > 0)
      {
        p[v] = u;
        if (v == si) return 1;
        vis[v] = 1;
        q.push(v);
      }
    }
  }

  return 0;
}

int maxflow(int so, int si)
{
  int mf = 0;

  while (bfs(so, si))
  {
    int f = inf;
    for (int u = si; u != so; u = p[u])
      f = min(f, flow[p[u]][u]);
    for (int u = si; u != so; u = p[u])
    {
      flow[p[u]][u] -= f;
      flow[u][p[u]] += f;
    }
    mf += f;
  }

  return mf;
}

inline bool check(int i, int j) { return i >= 0 && j >= 0 && terra[i][j]; }
inline int get(int i, int j) { return i * m + j; }

int main()
{
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> n >> m >> k && (n || m))
  {
    memset(terra, 1, sizeof terra);
    memset(flow, 0, sizeof flow);

    for (int i = 0; i < maxv; ++i) g[i].clear();
    for (int i = 0, x, y; i < k; ++i)
    {
      cin >> x >> y, --x, --y;
      terra[x][y] = 0;
    }

    int cnt = 2;
    map<int,int> mp;
    static const int I[] = {1, 0}, J[] = {0, 1};

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (terra[i][j])
          for (int k = 0; k < 2; ++k)
            if (check(i - I[k], j - J[k]))
            {
              int &mu = mp[get(i, j)];
              int &mv = mp[get(i - I[k], j - J[k])];
              if (!mu) mu = cnt++;
              if (!mv) mv = cnt++;
              int u = mu;
              int v = mv;
              if ((i + j) % 2) swap(u, v);
              g[0].pb(u);
              g[u].pb(0);
              g[u].pb(v);
              g[v].pb(u);
              g[1].pb(v);
              g[v].pb(1);
              flow[0][u] = 1;
              flow[u][v] = 1;
              flow[v][1] = 1;
            }

    cout << maxflow(0, 1) << '\n';
  }

  return 0;
}
