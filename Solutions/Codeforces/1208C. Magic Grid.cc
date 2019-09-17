#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e3 + 3;

int ans[maxn][maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i += 4) {
    for (int j = 0; j < n; j += 4) {
      for (int a = i; a < i + 4; ++a) {
        for (int b = j; b < j + 4; ++b) {
          ans[a][b] = cnt++;
        }
      }
    }
  }
  int x = 0, exp = 0;
  for (int i = 0; i < n; ++i) {
    x = 0;
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << ' ';
      x ^= ans[i][j];
    }
    cout << '\n';
    if (i == 0) {
      exp = x;
    } else if (x != exp) {
      assert(0);
    }
  }
  for (int j = 0; j < n; ++j) {
    x = 0;
    for (int i = 0; i < n; ++i) {
      x ^= ans[i][j];
    }
    assert(x == exp);
  }
  return 0;
}
