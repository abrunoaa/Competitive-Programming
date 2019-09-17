#include <bits/stdc++.h>
using namespace std;

const int maxn = 5003;

int a[maxn], dp[maxn][maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
      dp[n][j] = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] == a[j]) {
          dp[i][j] = 1 + dp[i + 1][j - 1];
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    cout << dp[0][n - 1] << '\n';
  }
  return 0;
}
