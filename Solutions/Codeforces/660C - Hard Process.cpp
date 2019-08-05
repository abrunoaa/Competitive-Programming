#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define size(x) (int)x.size()

int main() {
  // freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, k, e, i, j, ans, zeros;

  while (cin >> n >> k) {
    bool a[n + 3];
    for (i = 0; i < n; ++i) { cin >> a[i]; }

    for (i = j = ans = zeros = 0, e = -1; j < n; ++j) {
      if (!a[j]) {
        if (++zeros > k) {
          while (a[i++]);
          --zeros;
        }
      }
      if (j - i + 1 > ans) { ans = j - i + 1, e = j; }
    }

    cout << ans << endl;
    for (i = e; ans--; --i) { a[i] = 1; }

    cout << a[0];
    for (i = 1; i < n; ++i) { cout << ' ' << a[i]; }
    cout << endl;
  }

  return 0;
}

