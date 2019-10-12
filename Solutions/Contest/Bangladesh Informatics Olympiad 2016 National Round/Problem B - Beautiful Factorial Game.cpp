#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

vector<ii> fac(int k) {
  vector<ii> f;
  for (int d = 2; d * d <= k; ++d) {
    if (k % d == 0) {
      int e = 0;
      while (k % d == 0) {
        k /= d;
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
  long long x = p;
  while (x <= n) {
    k += (int)(n / x);
    x *= p;
  }
  return k;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, k;
    cin >> n >> k;
    int ans = 987654321;
    for (auto [p, e] : fac(k)) {
      int x = get(n, p);
      ans = min(ans, x / e);
    }
    cout << "Case " << t << ": " << ans << '\n';
  }
  return 0;
}
