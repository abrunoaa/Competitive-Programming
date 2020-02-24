#include <bits/stdc++.h>
using namespace std;

const int maxn = 103;

int b[maxn];
int a[2 * maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
 again:
  while (t--) {
    int n;
    cin >> n;
    set<int> disp;
    for (int i = 1; i <= 2 * n; ++i) {
      disp.insert(i);
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      disp.erase(b[i]);
    }
    for (int i = 0; i < n; ++i) {
      auto it = disp.upper_bound(b[i]);
      if (it == disp.end()) {
        cout << "-1\n";
        goto again;
      }
      a[2 * i] = min(b[i], *it);
      a[2 * i + 1] = max(b[i], *it);
      disp.erase(it);
    }
    for (int i = 0; i < 2 * n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
