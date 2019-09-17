#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = (int)1e9 + 7;

int mpow(int b, ll e) {
  int x = 1;
  while (e) {
    if (e & 1) x = (int)((ll)x * b % mod);
    e >>= 1;
    b = (int)((ll)b * b % mod);
  }
  return x;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    int r = (int)(n % 3);
    if (r == 0) {
      cout << mpow(3, n / 3) << '\n';
    } else if (r == 1) {
      cout << 4ull * mpow(3, (n - 4) / 3) % mod << '\n';
    } else {
      cout << 2 * mpow(3, (n - 2) / 3) % mod << '\n';
    }
  }
  return 0;
}
