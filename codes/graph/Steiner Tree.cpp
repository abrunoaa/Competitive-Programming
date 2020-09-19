#include <bits/stdc++.h>
using namespace std;

const int maxn = 103;

int n, k;
int x[maxn], y[maxn];
double cost[maxn][maxn];
double dp[1 << 10][maxn];

double run_dp() {                       // O(n^2 * 2^k + n * 3^k)
  for (int m = 0; m < (1 << k); ++m)
    for (int u = 0; u < n; ++u)
      dp[m][u] = 1e100;
  for (int u = 0; u < k; ++u)
    dp[1 << u][u] = 0;
  for (int m = 1; m < (1 << k); ++m)
    for (int u = 0; u < n; ++u) {
      auto &r = dp[m][u];
      for (int s = m; s; s = (s - 1) & m)       // all subsets of m
        r = min(r, dp[s][u] + dp[m - s][u]);    // subsets of subsets = 3^nbits
      if (r < 1e100)
        for (int v = k; v < n; ++v)       // starts from 0 if can connect pairs
          dp[m][v] = min(dp[m][v], r + cost[u][v]);
    }
  double ans = 1e100;
  for (int u = 0; u < n; ++u)
    ans = min(ans, dp[(1 << k) - 1][u]);
  return ans;
}

// spider man
struct tri {
  double a;
  int b, c;
  bool operator<(const tri& t) const { return (a > t.a); }
};

double dis[maxn][32];

double spider_man() {
  assert(k <= 5);
  for (int u = 0; u < n; ++u)
    for (int m = 0; m < (1 << k); ++m)
      dis[u][m] = 1e100;
  dis[0][1] = 0;                        // 0 is an endpoint
  priority_queue<tri> pq;
  pq.push({dis[0][1], 0, 1});
  while (!pq.empty()) {
    auto [d, u, m] = pq.top();
    pq.pop();
    if (d > dis[u][m]) continue;
    if (u >= k)                         // if two pairs can't connect directly
      for (int v = 0; v < k; ++v) {     // we will need this for loop
        int w = m | (1 << v);
        if (d + cost[u][v] < dis[u][w]) {
          dis[u][w] = d + cost[u][v];
          pq.push({dis[u][w], u, w});
        }
      }
    for (int v = k; v < n; ++v)
      if (d + cost[u][v] < dis[v][m]) {
        dis[v][m] = d + cost[u][v];
        pq.push({dis[v][m], v, m});
      }
  }
  double ans = 1e100;
  for (int u = 0; u < n; ++u)
    ans = min(ans, dis[u][(1 << k) - 1]);
  return ans;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cost[i][j] = cost[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
    }
  }
  if (k > 5) {
    cout << fixed << setprecision(5) << run_dp() << '\n';
  } else {
    cout << fixed << setprecision(5) << spider_man() << '\n';
  }
  return 0;
}
