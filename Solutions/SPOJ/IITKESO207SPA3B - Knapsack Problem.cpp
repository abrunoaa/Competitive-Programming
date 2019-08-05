#include <bits/stdc++.h>
using namespace std;

vector<int> w, v, ans;
vector<vector<int>> dp;

void rec(int i, int c) {
  if (i == 0) { return; }
  if (dp[i][c] == dp[i - 1][c]) { return rec(i - 1, c); }
  ans.push_back(w[i]);
  rec(i - 1, c - w[i]);
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  w.resize(n + 1);
  v.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
  }
  int c;
  cin >> c;
  dp.resize(n + 1, vector<int>(c + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= c; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= w[i]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
      }
    }
  }
  rec(n, c);
  sort(ans.begin(), ans.end());
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}
