#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

/// https://math.stackexchange.com/questions/301151/how-to-find-how-many-number-has-even-value-of-sigma-function
ull oddSigma(ull n) { return (int)(sqrt(n) + 1e-9) + (int)(sqrt(n / 2) + 1e-9); }

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  ull n;
  while (cin >> n && n) {
    cout << n - oddSigma(n) << '\n';
  }

  return 0;
}
