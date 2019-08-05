#include <bits/stdc++.h>
using namespace std;

int f[110];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  while (cin >> n && n) {
    memset(f, 0, sizeof f);
    for (int i = 0, x; i < n; ++i) {
      cin >> x;
      ++f[x];
    }

    bool flag = 0;
    for (int i = 0; i < 110; ++i) {
      for (int j = f[i]; j; --j) {
        if (flag) {
          cout << ' ';
        }
        flag = 1;
        cout << i;
      }
    }
    cout << '\n';
  }

  return 0;
}
