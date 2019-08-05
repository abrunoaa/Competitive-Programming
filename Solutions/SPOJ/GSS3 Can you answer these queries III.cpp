/* You are given a sequence A of N (N <= 50000) integers between -10000 and 10000.
 * On this sequence you have to apply M (M <= 50000) operations for given x, y:
 * - modify Ax by y;
 * - print max{ Ai + Ai+1 + .. + Aj | x <= i <= j <= y }.
 */
#include <bits/stdc++.h>
using namespace std;

#define maxn 50010
#define inf 0x3f3f3f3f
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

// ml/mr = max left/right; mt = max total; t = total
struct no { int ml, mr, mt, t; } st[4 * maxn];
int n, v[maxn];

no merge(const no &x, const no &y) {
  return no{ max(x.ml, x.t + y.ml),
             max(y.mr, y.t + x.mr),
             max(x.mr + y.ml, max(x.mt, y.mt)),
             x.t + y.t };
}

no &build(int k = 1, int l = 1, int r = n) {
  if (l == r) return st[k] = no{v[l], v[l], v[l], v[l]};
  return st[k] = merge(build(L, l, M), build(R, M + 1, r));
}

no qry(int i, int f, int k = 1, int l = 1, int r = n) {
  if (l > f or i > r) return no{-inf, -inf, -inf, 0};
  if (l >= i and f >= r) { return st[k]; }
  return merge(qry(i, f, L, l, M), qry(i, f, R, M + 1, r));
}

no upd(int i, int x, int k = 1, int l = 1, int r = n) {
  if (l == r && l == i) return st[k] = no{ x, x, x, x };
  if (i > M) { return st[k] = merge(st[L], upd(i, x, R, M + 1, r)); }
  return st[k] = merge(upd(i, x, L, l, M), st[R]);
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) { cin >> v[i]; }
  build();

  int op, m, x, y;
  cin >> m;
  while (m--) {
    cin >> op >> x >> y;
    if (op == 0) {
      upd(x, y);
    } else {
      cout << qry(x, y).mt << '\n';
    }
  }

  return 0;
}
