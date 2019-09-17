#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e6 + 3;

vector<int> g[maxn];
int t, num[maxn];

void bfs(int beg) {
  ++t;
  queue<int> q;
  q.push(beg);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    num[u] = t;
    for (int v : g[u]) {
      if (!num[v]) {
        q.push(v);
      }
    }
  }
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n >> k;
  while (k--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int u = 1; u <= n; ++u) {
    if (!num[u]) {
      bfs(u);
    }
  }
  for (int u = 1; u <= n / 2; ++u) {
    if (num[u] != num[n - u + 1]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
