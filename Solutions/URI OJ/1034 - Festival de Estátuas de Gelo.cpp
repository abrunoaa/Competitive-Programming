#include <bits/stdc++.h>
using namespace std;

const int maxm = (int)1e6 + 3;

int dp[maxm];

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    memset(dp + 1, 63, m * sizeof(*dp));
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      for (int j = a; j <= m; ++j) {
        dp[j] = min(dp[j], dp[j - a] + 1);
      }
    }
    cout << dp[m] << '\n';
  }
  return 0;
}
