#include <bits/stdc++.h>
using namespace std;

#define mod int(1e9 + 7)

int n, k, f[2010];

int main() {
  cin >> n >> k;
  if (k == 1) {
    cout << n << '\n';
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    f[i] = n / i;
  }
  for (int i = 0; i < k - 2; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 2 * j; k <= n; k += j) {
        f[j] = (f[j] + f[k]) % mod;
      }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + f[i]) % mod;
  }
  cout << ans << '\n';

  return 0;
}
