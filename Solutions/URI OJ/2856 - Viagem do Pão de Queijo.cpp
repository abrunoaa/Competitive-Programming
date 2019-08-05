#include <bits/stdc++.h>
using namespace std;

#define maxn 1002

int n, r, x[maxn], y[maxn], z[maxn], pd[maxn][maxn];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> r;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> x[i] >> c >> y[i];
    z[i] = (c == 'B' ? 0 : c == 'C' ? 1 : 2);
  }

  int ans = 0;
  for (int k = 1; k < 7; ++k) {
    for (int j = 0; j <= r; ++j) {
      pd[n][j] = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j <= r; ++j) {
        if (j < y[i] || !(k & (1 << z[i]))) {
          pd[i][j] = pd[i + 1][j];
        } else {
          pd[i][j] = max(pd[i + 1][j], x[i] + pd[i + 1][j - y[i]]);
        }
      }
    }
    ans = max(ans, pd[0][r]);
  }

  cout << ans << '\n';
  return 0;
}
