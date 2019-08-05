#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("in", "r", stdin);

  int n;
  while (cin >> n) {
    map<int, bool> mp[n];

    for (int i = 0; i < n; ++i)
      for (int j = 0, t; j < 6; ++j) {
        cin >> t, mp[i][t] = 1;
      }

    int i;
    for (i = 1; i < 1000; ++i) {
      int c = i % 10, b = i / 10 % 10, a = i / 100;

      for (int j = 0; j < n; ++j)
        if (!a || mp[j][a]) {
          for (int k = 0; k < n; ++k)
            if ((!a && !b) || (mp[k][b] && j != k)) {
              for (int l = 0; l < n; ++l)
                if (mp[l][c] && (!a || l != j) && ((!a && !b) || l != k)) {
                  goto ok;
                }
            }
        }

      break;
    ok:
      continue;
    }

    cout << i - 1 << '\n';
  }

  return 0;
}
