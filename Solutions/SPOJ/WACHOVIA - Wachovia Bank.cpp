#include <bits/stdc++.h>
using namespace std;

int dp[1003];

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    memset(dp, 0, (m + 1) * sizeof(dp[0]));
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      for (int j = m; j >= a; --j) {
        dp[j] = max(dp[j], dp[j - a] + b);
      }
    }
    cout << "Hey stupid robber, you can get " << dp[m] << ".\n";
  }
  return 0;
}
