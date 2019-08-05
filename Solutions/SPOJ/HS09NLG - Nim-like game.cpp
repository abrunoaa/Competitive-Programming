#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

#define maxp 305

int pd[maxp][2 * maxp];

void build() {
  bool see[2 * maxp];
  for (int n = 1; n < maxp; ++n) {
    for (int m = 0; m < 2 * maxp; ++m) {
      memset(see, 0, sizeof see);
      int u = (m == 0 ? n - 1 : min(n, 2 * m));
      for (int k = 1; k <= u; ++k) {
        see[pd[n - k][k]] = 1;
      }
      for (int k = 0; ; ++k) {
        if (!see[k]) {
          pd[n][m] = k;
          break;
        }
      }
    }
  }
}

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  build();

  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;

    int x = 0;
    for (int i = 0, y; i < n; ++i) {
      cin >> y;
      x ^= pd[y][0];
    }

    cout << (x != 0) << '\n';
  }

  return 0;
}
