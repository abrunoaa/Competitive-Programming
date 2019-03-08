#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define pb push_back

typedef vector<int> vi;

int N, M, Q, p[maxn][20] = {}, h[maxn];
vector<int> g[maxn];
vi peopleAt[maxn], people[maxn][20];

vi join(vi p, const vi &q)
{
  p.insert(p.end(), q.begin(), q.end());
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  if (p.size() > 10) p.erase(p.begin() + 10, p.end());
  return p;
}

void dfsLca(int u, int pai)
{
  for (int i = 0; i < (int)g[u].size(); ++i)
  {
    int v = g[u][i];
    if (v != pai)
    {
      p[v][0] = u;
      people[v][0] = join(peopleAt[u], peopleAt[v]);
      h[v] = h[u] + 1;
      dfsLca(v, u);
    }
  }
}

void buildLca()
{
  h[0] = 0;
  dfsLca(0, 0);
  for (int i = 1; i < 20; ++i)
    for (int u = 0; u < N; ++u)
    {
      int v = p[u][i - 1];
      p[u][i] = p[v][i - 1];
      people[u][i] = join(people[u][i - 1], people[v][i - 1]);
    }
}

vi lca(int u, int v)
{
  if (h[u] < h[v]) swap(u, v);

  vi ans;

  if (h[u] != h[v])
    for (int i = 20, d = h[u] - h[v]; i--; )
      if (d & (1 << i))
      {
        ans = join(ans, people[u][i]);
        u = p[u][i];
      }

  if (u == v) return join(ans, peopleAt[u]);

  for (int i = 20; i--; )
    if (p[u][i] != p[v][i])
    {
      ans = join(ans, join(people[u][i], people[v][i]));
      u = p[u][i];
      v = p[v][i];
    }

  return join(ans, join(people[u][0], people[v][0]));
}

int main()
{
  // freopen("br", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> N >> M >> Q;
  for (int i = 0, u, v; i < N - 1; ++i)
  {
    cin >> u >> v, --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  for (int i = 1, c; i <= M; ++i)
  {
    cin >> c, --c;
    if (peopleAt[c].size() < 10) peopleAt[c].push_back(i);
  }

  buildLca();
  for (int i = 0, v, u, a; i < Q; ++i)
  {
    cin >> v >> u >> a, --v, --u;
    vi ans = lca(u, v);
    int k = min((int)ans.size(), a);
    cout << k;
    for (int i = 0; i < k; ++i) cout << ' ' << ans[i];
    cout << '\n';
  }

  return 0;
}
