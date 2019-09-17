#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5 + 3;
const int maxs = (int)sqrt(maxn) + 3;

int u[maxn];
int v[maxs][maxs];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int n, q;
  cin >> n >> q;
  const int bs = (int)sqrt(n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b, c;
      cin >> a >> b >> c;
      if (b <= bs) {
        v[b][a] += c;
      } else {
        for (int i = a; i <= n; i += b) {
          u[i] += c;
        }
      }
    } else {
      int d;
      cin >> d;
      int ans = u[d];
      for (int i = 1; i <= bs; ++i) {
        ans += v[i][d % i];
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
