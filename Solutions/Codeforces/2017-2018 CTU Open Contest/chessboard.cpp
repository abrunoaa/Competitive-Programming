#include <bits/stdc++.h>
using namespace std;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int s;
  char p;
  while (cin >> s >> p) {
    int ans;
    if (p == 'B' || p == 'R') {
      ans = s;
    } else if (p == 'K') {
      ans = (s == 1 ? 1 : 4);
    } else {
      ans = (s <= 2 ? 1 : 2);
    }
    cout << ans << '\n';
  }
  return 0;
}
