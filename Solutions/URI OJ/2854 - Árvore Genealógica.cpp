#include <bits/stdc++.h>
using namespace std;

#define maxn 302

int p[maxn];

int find(int u) {
  return (u == p[u] ? u : p[u] = find(p[u]));
}

bool unite(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    return 0;
  }
  p[u] = p[v];
  return 1;
}

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  for (int i = 0; i < maxn; ++i) {
    p[i] = i;
  }

  int m, n;
  cin >> m >> n;

  int cnt = 0, ans = m;
  map<string, int> mp;
  while (n--) {
    string a, b, c;
    cin >> a >> b >> c;

    int &x = mp[a];
    int &y = mp[c];
    if (!x) { x = ++cnt; }
    if (!y) { y = ++cnt; }

    ans -= unite(x, y);
  }

  cout << ans << '\n';

  return 0;
}
