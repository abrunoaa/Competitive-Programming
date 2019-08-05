/* You are given a sequence A[1], A[2], ..., A[N]. (|A[i]| ≤ 10000, 1 ≤ N ≤ 10000).
 * A query is defined as follows:
 * Query(x1,y1,x2,y2) =
 *          max { A[i]+A[i+1]+...+A[j] ; x1 ≤ i ≤ y1, x2 ≤ j ≤ y2 and x1 ≤ x2, y1 ≤ y2 }
 */
#include <bits/stdc++.h>
using namespace std;

#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)
#define maxn 10010
#define inf 0x3f3f3f3f

struct no { int ml, mr, mt, t; } segt[4 * maxn];
int n, v[maxn];

no merge(const no &x, const no &y) {
  return no{ max(x.ml, x.t + y.ml),
             max(y.mr, y.t + x.mr),
             max(x.mr + y.ml, max(x.mt, y.mt)),
             x.t + y.t };
}

no build(int k = 1, int l = 1, int r = n) {
  if (l == r) return segt[k] = no{ v[l], v[l], v[l], v[l] };
  return segt[k] = merge(build(L, l, M), build(R, M + 1, r));
}

no qry(int i, int j, int k = 1, int l = 1, int r = n) {
  if (i > r or l > j) return no{ -inf, -inf, -inf, 0 };
  if (i <= l and r <= j) { return segt[k]; }
  return merge(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

int ans(int x1, int y1, int x2, int y2) {
  if (x2 < x1) { swap(x1, x2), swap(y1, y2); }

  // i ∈ [x1,y1], j ∈ [x2,y2]
  if (y1 < x2) { return qry(y1 + 1, x2 - 1).t + qry(x1, y1).mr + qry(x2, y2).ml; }
  return max(qry(x1, x2).mr + qry(x2, y2).ml - v[x2],     // i ∈ [x1,x2], j ∈ [x2,y2]
             max(qry(x1, y1).mr + qry(y1, y2).ml - v[y1], // i ∈ [x1,y1], j ∈ [y1,y2]
                 qry(x2, y1).mt));                        // i,j ∈ [x2,y1]
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) { cin >> v[i]; }
    build();

    int m, x1, y1, x2, y2;
    cin >> m;
    while (m--) {
      cin >> x1 >> y1 >> x2 >> y2;
      cout << ans(x1, y1, x2, y2) << '\n';
    }
  }

  return 0;
}
