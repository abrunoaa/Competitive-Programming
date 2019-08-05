#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 110
#define fst first
#define snd second

typedef pair<int, int> ii;

int memo[maxn][maxn];
vector<ii> g[maxn], g2[maxn];

void dfs(int u, int p) {
  for (int i = 0; i < (int)g2[u].size(); ++i) {
    ii v = g2[u][i];
    if (v.fst != p) {
      g[u].push_back(v);
      dfs(v.fst, u);
    }
  }
}

int apples(int p, int i, int q) {
  if (i == (int)g[p].size()) { return 0; } //(!q ? 0 : -inf);
  if (!q) { return 0; }

  ii u = g[p][i];
  int &pd = memo[u.fst][q];
  if (pd != -1) { return pd; }

  pd = apples(p, i + 1, q);
  for (int c = 1; c <= q; ++c) {
    int x = u.snd + apples(p, i + 1, q - c) + apples(u.fst, 0, c - 1);
    pd = max(pd, x);
  }

  // cerr << " >> " << p << ' ' << i << " == " << u.fst << ": " << q << " == " << pd << endl;
  return pd = max(pd, 0);
}

int main() {
  // freopen("bin", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, q;

  cin >> n >> q;
  for (int i = 0, u, v, w; i < n - 1; ++i) {
    cin >> u >> v >> w;
    g2[u].push_back(ii(v, w));
    g2[v].push_back(ii(u, w));
  }

  dfs(1, 0);
  g[0].push_back(ii(1, 0));
  memset(memo, -1, sizeof memo);
  cout << apples(0, 0, q + 1) << '\n';

  return 0;
}
