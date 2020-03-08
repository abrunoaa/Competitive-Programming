#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5 + 3;

int p[maxn];
int d[maxn];
int v[maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  sort(p, p + n);

  for (int i = 0; i < m; ++i) {
    cin >> v[i];
    d[i] = k;
  }
  sort(v, v + m);

  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    for (; j < m && (d[j] == 0 || p[i] - v[j] > t); ++j) {
    }
    if (j == m) {
      break;
    }
    if (abs(p[i] - v[j]) <= t) {
      ++ans;
      --d[j];
    }
  }
  cout << ans << '\n';
  return 0;
}
