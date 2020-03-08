#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  int x = n;
  for (int i = 0; i < n; ++i) {
    if (k >= x - 1) {
      k -= x - 1;
      cout << x << ' ';
      --x;
    } else {
      cout << k + 1 << ' ';
      x = 1;
      while (++i < n) {
        if (x == k + 1) {
          ++x;
        }
        cout << x << ' ';
        ++x;
      }
    }
  }
  cout << '\n';
  return 0;
}
