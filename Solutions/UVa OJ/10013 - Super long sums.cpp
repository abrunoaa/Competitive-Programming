#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

int x[maxn], y[maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) { cin >> x[i] >> y[i]; }

    x[0] = 0;
    for (int i = n; i > 0; --i) {
      x[i] += y[i];
      if (x[i] > 9) {
        x[i] -= 10;
        ++x[i - 1];
      }
    }

    int p = 0;
    for (; !x[p]; ++p);
    for (int i = p; i <= n; ++i) { cout << x[i]; }
    cout << '\n';
    if (t) { cout << '\n'; }
  }

  return 0;
}
