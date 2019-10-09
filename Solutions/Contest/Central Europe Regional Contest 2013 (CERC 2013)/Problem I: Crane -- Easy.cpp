#include <bits/stdc++.h>
using namespace std;

const int maxn = 10003;

int a[maxn];
vector<pair<int,int>> ans;

void exchange(int l, int r) {
  assert((r - l + 1) % 2 == 0);
  ans.emplace_back(l, r);
  int m = (r - l + 1) / 2;
  for (int i = l; i < l + m; ++i) {
    swap(a[i], a[i + m]);
  }
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] != i) {
        int j;
        for (j = i; a[j] != i; ++j);
        int len = j - i;
        if (i + 2 * len - 1 > n) {
          exchange(i + (n - i + 1) % 2, n);
          for (j = i; a[j] != i; ++j);
          len = j - i;
        }
        exchange(i, i + 2 * len - 1);
      }
    }
    cout << ans.size() << '\n';
    for (auto &p : ans) {
      int l, r;
      tie(l, r) = p;
      cout << l << ' ' << r << '\n';
    }
    ans.clear();
  }
  return 0;
}
