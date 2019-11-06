#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5 + 3;

int need;
vector<int> ans[maxn];
vector<pair<int,int>> g[maxn];

void dfs(int u, int p, int day) {
  int d = 0;
  for (auto [v, i] : g[u]) {
    if (v != p) {
      ++d;
      if (d == day) {
        ++d;
      }
      dfs(v, u, d);
      ans[d].push_back(i);
      need = max(need, d);
    }
  }
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }
  dfs(1, 0, 0);
  cout << need << '\n';
  for (int i = 1; i <= need; ++i) {
    cout << ans[i].size();
    for (int x : ans[i]) {
      cout << ' ' << x;
    }
    cout << '\n';
  }
  return 0;
}
