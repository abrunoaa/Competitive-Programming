#include <bits/stdc++.h>
using namespace std;

#define maxn 2010
#define maxa 5010

typedef long long ll;
typedef double lf;

int a[maxn], f[maxa], g[maxa];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ++f[abs(a[i] - a[j])];
    }
  }
  for (int i = 5000; i >= 0; --i) {
    g[i] = g[i + 1] + f[i];
  }

  ll ans = 0;
  for (int i = 0; i < 5000; ++i) {
    for (int j = 0; i + j < 5000; ++j) {
      ans += (ll)f[i] * f[j] * g[i + j + 1];
    }
  }

  int k = n * (n - 1) / 2;
  cout << fixed << setprecision(20) << lf(ans) / ((ll)k * k * k) << '\n';

  return 0;
}
