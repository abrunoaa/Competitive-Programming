#include <bits/stdc++.h>
using namespace std;

const int maxn = 103;

int x[maxn], y[maxn];
double cost[maxn][maxn];
double dp[1 << 10][maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cost[i][j] = cost[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
    }
  }
  for (int m = 0; m < (1 << k); ++m) {
    for (int u = 0; u < n; ++u) {
      dp[m][u] = 1e100;
    }
  }
  for (int u = 0; u < k; ++u) {
    dp[1 << u][u] = 0;
  }
  for (int m = 1; m < (1 << k); ++m) {
    for (int u = 0; u < n; ++u) {
      auto &r = dp[m][u];
      for (int s = m; s; s = (s - 1) & m) {
        r = min(r, dp[s][u] + dp[m - s][u]);
      }
      if (r < 1e100) {
        for (int v = k; v < n; ++v) {
          dp[m][v] = min(dp[m][v], r + cost[u][v]);
        }
      }
    }
  }
  double ans = 1e100;
  for (int u = 0; u < n; ++u) {
    ans = min(ans, dp[(1 << k) - 1][u]);
  }
  cout << fixed << setprecision(5) << ans << '\n';
  return 0;
}
