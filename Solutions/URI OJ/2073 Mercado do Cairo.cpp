#include <bits/stdc++.h>
using namespace std;

#define maxd 1010

int bit[maxd][maxd];

void upd(int x, int y, int v) {
  for (int i = x; i < maxd; i += i & -i)
    for (int j = y; j < maxd; j += j & -j) {
      bit[i][j] = max(bit[i][j], v);
    }
}

int qry(int x, int y) {
  int ans = 0;
  for (int i = x; i; i -= i & -i)
    for (int j = y; j; j -= j & -j) {
      ans = max(ans, bit[i][j]);
    }

  return ans;
}

int main() {
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    memset(bit, 0, sizeof bit);

    int n;
    cin >> n;
    while (n--) {
      int x, y;
      cin >> x >> y;
      upd(x, y, qry(x, y) + 1);
    }

    cout << qry(maxd - 1, maxd - 1) << '\n';
  }

  return 0;
}
