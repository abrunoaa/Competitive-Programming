#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e7 + 3;

long long dp[2 * maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  int n, x, y;
  cin >> n >> x >> y;
  memset(dp, 63, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = min(dp[i], dp[i - 1] + x);
    dp[2 * i] = min(dp[2 * i], dp[i] + y);
    dp[2 * i - 1] = min(dp[2 * i - 1], dp[2 * i] + x);
  }
  cout << dp[n] << '\n';
  return 0;
}
