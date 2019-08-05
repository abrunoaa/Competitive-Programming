#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, k;
  cin >> n >> k;

  int ans = 0;
  multiset<int> s;
  for (int i = 1, p; i <= n; ++i) {
    cin >> p;
    ans += p;
    s.insert(p);
    int m = i / (k + 1);
    while ((int)s.size() > m) {
      s.erase(s.begin());
    }
  }
  for (int x : s) {
    ans -= x;
  }
  cout << ans << '\n';

  return 0;
}
