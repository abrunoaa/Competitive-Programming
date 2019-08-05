#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    int x;
    cin >> x;
    ans += t == x;
  }
  cout << ans << '\n';
  return 0;
}
