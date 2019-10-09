#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define lg(x) (31 - __builtin_clz(x))

typedef long long ll;

const int maxn = (int)1e5 + 3;

int n;
ll a[maxn][lg(maxn) + 2];

void build() {
  for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 0; i + (1 << j) <= n; ++i) {
      a[i][j] = gcd(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
    }
  }
}

ll qry(int i, int j) {
  int k = lg(j - i + 1);
  return gcd(a[i][k], a[j - (1 << k) + 1][k]);
}

int find(int i, ll g) {
  int l = i + 1, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (g <= qry(i, m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  // assert(qry(i, l - 1) == g);
  return l - 1;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    // n = 1e5;
    for (int i = 0; i < n; ++i) {
      cin >> a[i][0];
      // a[i][0] = rand();
    }
    build();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      // cerr << " >> " << i << endl;
      ll g = a[i][0];
      while (1) {
        int j = find(i, g);
        // cerr << " ## " << i << ' ' << j << ' ' << g << endl;
        ans = max(ans, g * (j - i + 1));
        if (j + 1 == n) {
          break;
        }
        // assert(i <= j);
        // assert(qry(i, j + 1) < g);
        g = qry(i, j + 1);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
