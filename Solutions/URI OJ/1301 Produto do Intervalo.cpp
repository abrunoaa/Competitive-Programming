#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define sign(x) ((x > 0) - (x < 0))
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

int n, m, v[maxn], st[4 * maxn];

int build(int k = 1, int l = 1, int r = n) {
  if (l == r) { return st[k] = sign(v[l]); }
  return st[k] = build(L, l, M) * build(R, M + 1, r);
}

int upd(int i, int v, int k = 1, int l = 1, int r = n) {
  if (l == r && l == i) { return st[k] = sign(v); }
  if (i > M) { return st[k] = st[L] * upd(i, v, R, M + 1, r); }
  return st[k] = upd(i, v, L, l, M) * st[R];
}

int qry(int i, int j, int k = 1, int l = 1, int r = n) {
  if (r < i || j < l) { return 1; }
  if (i <= l && r <= j) { return st[k]; }
  return qry(i, j, L, l, M) * qry(i, j, R, M + 1, r);
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) { cin >> v[i]; }
    build();
    while (m--) {
      char op;
      int i, j;
      cin >> op >> i >> j;
      if (op == 'C') {
        upd(i, j);
      } else {
        int x = qry(i, j);
        cout << (x == 0 ? '0' : x > 0 ? '+' : '-');
      }
    }
    cout << '\n';
  }

  return 0;
}
