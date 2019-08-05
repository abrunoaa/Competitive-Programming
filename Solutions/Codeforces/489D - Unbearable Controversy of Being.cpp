#include <bits/stdc++.h>
using namespace std;

#define maxn 3010

int n, m, reach[maxn][maxn];
vector<int> g[maxn];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j : g[i])
      for (int k : g[j])
        if (i != k) {
          ans += reach[i][k]++;
        }
  cout << ans << '\n';

  return 0;
}
