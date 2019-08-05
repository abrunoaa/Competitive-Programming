#include <bits/stdc++.h>
using namespace std;

vector<int> x[10010];

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int g;
  cin >> g;
  for (int i = 0, a, b; i < g; ++i) {
    cin >> a >> b;
    x[a].push_back(b);
  }
  for (int i = 0; i <= 10000; ++i) {
    sort(x[i].begin(), x[i].end());
  }

  int m;
  cin >> m;
  while (m--) {
    int xc, yc, r;
    cin >> xc >> yc >> r;
    for (int i = max(0, xc - r), j = min(10000, xc + r); i <= j; ++i) {
      if (!x[i].empty()) {
        int yl = ceil(yc - sqrt(r * r - (i - xc) * (i - xc)));
        int yu = yc + sqrt(r * r - (i - xc) * (i - xc));
        int p1 = lower_bound(x[i].begin(), x[i].end(), yl) - x[i].begin();
        int p2 = upper_bound(x[i].begin(), x[i].end(), yu) - x[i].begin();
        if (p1 < p2) {
          x[i].erase(x[i].begin() + p1, x[i].begin() + p2);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= 10000; ++i) {
    ans += x[i].size();
  }
  cout << ans << '\n';

  return 0;
}
