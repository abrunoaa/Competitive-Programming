#include <bits/stdc++.h>
using namespace std;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int i;
    for (i = 0; y[i] != '1'; ++i);
    int j;
    for (j = i; x[j] != '1'; ++j);
    cout << j - i << '\n';
  }
  return 0;
}
