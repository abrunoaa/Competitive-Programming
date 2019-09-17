#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, a[maxn];
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    int d = a[n] - a[n - 1];
    int k;
    for (k = n - 2; k && a[k] + d == a[k + 1]; --k);
    cout << k + 1 << '\n';
  }
  return 0;
}
