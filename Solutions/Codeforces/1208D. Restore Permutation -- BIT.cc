#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = (int)2e5 + 3;

int n, s[maxn];
int ans[maxn];
int bit[maxn];

void upd(int i, int x) {
  for (; i <= n; i += i & -i) {
    bit[i] += x;
  }
}

int find(int x) {
  int k = 0;
  for (int i = (1 << 20); i; i /= 2) {
    if (k + i <= n && bit[k + i] <= x) {
      x -= bit[k + i];
      k += i;
    }
  }
  return k;
}

signed main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    upd(i, i);
  }
  for (int i = n; i; --i) {
    int k = find(s[i]) + 1;
    ans[i] = k;
    upd(k, -k);
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
