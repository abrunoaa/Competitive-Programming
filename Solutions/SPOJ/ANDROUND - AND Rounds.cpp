#include <bits/stdc++.h>
using namespace std;

#define maxn 20010
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

int n, k, v[maxn], st[4 * maxn];

int build(int k = 1, int l = 0, int r = n - 1) {
  if (l == r) { return st[k] = v[l]; }
  return st[k] = build(L, l, M) & build(R, M + 1, r);
}

int qry(int i, int j, int k = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return -1; }
  if (i <= l && r <= j) { return st[k]; }
  return qry(i, j, L, l, M) & qry(i, j, R, M + 1, r);
}

int query(int i, int j) {
  if (i < 0) { return qry(0, j) & qry(n + i, n - 1); }
  if (j >= n) { return qry(i, n - 1) & qry(0, j - n); }
  return qry(i, j);
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) { cin >> v[i]; }
    build();

    if (k > n / 2) {
      int ans = qry(0, n - 1);
      for (int i = 0; i < n; ++i) { cout << ans << ' '; }
    } else {
      for (int i = 0; i < n; ++i) { cout << query(i - k, i + k) << ' '; }
    }
    cout << '\n';
  }

  return 0;
}
