#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  // freopen("in", "r", stdin);

  int n, ans, l, i, v[100100];

  while (cin >> n) {
    cin >> v[0];
    ans = l = 1;

    for (i = 1; i < n; ++i, ++l) {
      cin >> v[i];
      if (v[i] < v[i - 1]) { ans = max(ans, l), l = 0; }
    }

    cout << max(ans, l) << '\n';
  }

  return 0;
}
