#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll C(int n, int k) {
  k = min(k, n - k);
  ll c = 1;
  for (int i = 0; i < k; ++i) {
    c = c * (n - i) / (i + 1);
  }
  return c;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    cout << C(n - 1, k - 1) << '\n';
  }

  return 0;
}
