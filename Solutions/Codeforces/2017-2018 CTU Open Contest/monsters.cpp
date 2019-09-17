#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5 + 3;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, a[maxn];
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      while (a[i] != i) {
        swap(a[i], a[a[i]]);
        ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
