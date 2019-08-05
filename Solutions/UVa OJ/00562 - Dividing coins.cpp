#include <bits/stdc++.h>
using namespace std;

int main() {
  // assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int total = 0;
    vector<int> v(n);
    for (int &x : v) {
      cin >> x;
      total += x;
    }
    int m = total / 2;
    vector<int> pd(m + 1);
    for (int x : v) {
      for (int i = m; i >= x; --i) {
        pd[i] = max(pd[i], x + pd[i - x]);
      }
    }
    cout << abs(2 * pd[m] - total) << '\n';
  }
  return 0;
}
