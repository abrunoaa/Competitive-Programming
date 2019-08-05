#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

char vis[maxn];
int n, m, dis[maxn];
vector<int> g[maxn];

void diameter(int u, int d, int cmp, int &ans, int &ansd) {
  if (d > ansd) {
    ansd = d;
    ans = u;
  }

  vis[u] = 2;
  for (int v : g[u]) {
    if (vis[v] == cmp) {
      diameter(v, d + 1, cmp, ans, ansd);
    }
  }
  vis[u] = 1;
}

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  if (n == 2) {
    cout << "1\n";
    return 0;
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 0;
  for (int u = 0; u < n; ++u) {
    if (!vis[u]) {
      int v;
      int &d = dis[u] = -1;
      diameter(u, 0, 0, v, d);
      diameter(v, 0, 1, v, d);

      ans = max(ans, d);
      d = (d + 1) / 2;
    }
  }

  sort(dis, dis + n, greater<int>());
  ans = max(ans, max(dis[0] + dis[1] + 1, dis[1] + dis[2] + 2));

  cout << ans << '\n';

  return 0;
}
