#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p10[19], nine[19];

void build() {
  p10[0] = 1;
  nine[0] = 0;
  for (int i = 1; i < 19; ++i) {
    p10[i] = p10[i - 1] * 10;
    nine[i] = nine[i - 1] * 10 + 90;
  }
}

ll f(ll n) {
  if (n <= 9) { return n; }

  ll ans = 9;
  for (int k = 0; k < 18; ++k) {
    for (int x = 1; x <= 9; ++x) {
      if (x * p10[k + 1] + nine[k] + x >= n) {
        if (n < 100) { return ans + (x * p10[k + 1] + nine[k] + x == n); }

        ans += n / 10 + (n % 10 >= x);
        int p;
        for (p = 0; n > 9; n /= 10, ++p);
        return ans - n * p10[p] / 10;
      }
      ans += p10[k];
    }
  }
  assert(0);
}

int main() {
  build();

  ll l, r;
  while (cin >> l >> r) {
    // cerr << " >> " << f(r) << ' ' << f(l - 1) << endl;
    cout << f(r) - f(l - 1) << '\n';
  }

  return 0;
}
