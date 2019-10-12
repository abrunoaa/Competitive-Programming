#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int> ii;

vector<ii> factors(int k) {
  vector<ii> f;
  for (int d = 2; d * d <= k; ++d) {
    if (k % d == 0) {
      int e = 1;
      while ((k /= d) % d == 0) {
        ++e;
      }
      f.emplace_back(d, e);
    }
  }
  if (k > 1) {
    f.emplace_back(k, 1);
  }
  return f;
}

int get(int n, int p) {
  int k = 0;
  while ((n /= p)) {
    k += n;
  }
  return k;
}

signed main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, k;
    cin >> n >> k;
    int ans = (int)8e18;
    for (auto [p, e] : factors(k)) {
      ans = min(ans, get(n, p) / e);
    }
    cout << ans << '\n';
  }
  return 0;
}
