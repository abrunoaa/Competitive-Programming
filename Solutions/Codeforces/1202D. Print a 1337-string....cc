#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m = (int)sqrt(2 * n);
    while (m * (m + 1) / 2 <= n) {
      ++m;
    }
    int k = n - m * (m - 1) / 2;
    cout << '1' << string(m - 2, '3') << string(k, '1') << "337\n";
  }
  return 0;
}
