#include <bits/stdc++.h>
using namespace std;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, p;
    string s;
    cin >> a >> b >> p >> s;
    int n = (int)s.size();
    long long cost = s[n - 2] == 'A' ? a : b;
    if (cost > p) {
      cout << n << '\n';
      continue;
    }
    int ans;
    for (ans = n - 2; ans > 0; --ans) {
      if (s[ans] != s[ans - 1]) {
        cost += s[ans - 1] == 'A' ? a : b;
      }
      if (cost > p) {
        break;
      }
    }
    cout << ans + 1 << '\n';
  }
  return 0;
}
