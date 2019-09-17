#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = (int)1e5 + 3;

bool use[maxn];
int n, a[maxn], b[maxn];

main() {
  assert(freopen("fenwick.in", "r", stdin));
  assert(freopen("fenwick.out", "w", stdout));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i += 2) {
    int sum = 0;
    for (int j = i - (i & -i) + 1; j < i - 1; ++j) {
      if (!use[j]) {
        use[j] = 1;
        b[j] = a[j];
      }
      sum += b[j];
    }
    b[i - 1] = -sum;
    use[i - 1] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    cout << (!use[i] ? a[i] : b[i]) << ' ';
  }
  cout << '\n';
  return 0;
}
