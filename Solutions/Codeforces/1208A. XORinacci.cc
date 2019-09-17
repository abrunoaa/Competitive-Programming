#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;
    n %= 3;
    if (n == 0) {
      cout << a << '\n';
    } else if (n == 1) {
      cout << b << '\n';
    } else {
      cout << (a ^ b) << '\n';
    }
  }
  return 0;
}
