#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("in597A", "r", stdin);

  long long a, b, k;

  while (cin >> k >> a >> b) {
    if (a % k) {
      if (a < 0) { a -= a % k; }
      else { a += k - a % k; }
    }
    if (b % k) {
      if (b < 0) { b -= k + b % k; }
      else { b -= b % k; }
    }
//cout << " >> " << a << ' ' << b << " :: ";
    if (a > b) {
      puts("0");
    } else {
      cout << (b - a + k) / k << '\n';
    }
  }

  return 0;
}
