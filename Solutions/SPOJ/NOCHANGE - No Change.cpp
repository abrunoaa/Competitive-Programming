#include <bits/stdc++.h>
using namespace std;

bool dp[int(1e5 + 3)];

int main() {
  int x, k;
  cin >> x >> k;
  int s = 0;
  dp[0] = 1;
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    s += c;
    for (int j = s; j <= x; ++j) {
      dp[j] |= dp[j - s];
    }
  }
  cout << (dp[x] ? "YES" : "NO") << '\n';
  return 0;
}
