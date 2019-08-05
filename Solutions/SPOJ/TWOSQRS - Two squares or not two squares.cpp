#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010  // sqrt(1e12)

typedef long long ll;

int main() {
  int t;
  cin >> t;
again:
  while (t--) {
    ll n;
    cin >> n;
    for (ll y = 0; y * y <= n; ++y) {
      ll x = sqrt(n - y * y);
      if (x * x + y * y == n) {
        cout << "Yes\n";
        goto again;
      }
    }
    cout << "No\n";
  }

  return 0;
}
