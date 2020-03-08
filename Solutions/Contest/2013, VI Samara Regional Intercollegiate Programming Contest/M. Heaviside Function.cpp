#include <bits/stdc++.h>
using namespace std;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> g, l;
  for (int i = 0; i < n; ++i) {
    int s, a;
    cin >> s >> a;
    if (s == 1) {
      g.push_back(a);
    } else {
      l.push_back(-a);
    }
  }
  sort(g.begin(), g.end());
  sort(l.begin(), l.end());
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    int ans = (int)(upper_bound(g.begin(), g.end(), x) - g.begin());
    ans += (int)(l.end() - lower_bound(l.begin(), l.end(), x));
    cout << ans << '\n';
  }
  return 0;
}
