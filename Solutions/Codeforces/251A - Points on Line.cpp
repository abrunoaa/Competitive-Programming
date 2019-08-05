#include <bits/stdc++.h>
using namespace std;

#define maxn 100010

typedef long long ll;

int x[maxn];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, d;
  while (cin >> n >> d) {
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }

    ll ans = 0;
    for (int i = 0, l = 0; i < n; ++i) {
      while (x[i] > x[l] + d) {
        ++l;
      }
      int k = i - l;
      ans += (ll)k * (k - 1) / 2;
    }

    cout << ans << '\n';
  }

  return 0;
}
