/* SPOJ: KQUERYO - K-Query Online:
 * Given a sequence of n numbers a1, a2, ..., an and a number of k-queries.
 * A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n).
 * For each k-query (i, j, k), you have to return the number of elements greater than k
 * in the subsequence ai, ai+1, ..., aj.
 */

#include <bits/stdc++.h>
using namespace std;

#define maxn 30010
#define L (k << 1)        // left child of node
#define R (L + 1)         // right child of node
#define M ((l + r) >> 1)  // mid of two segments

int n, q, a[maxn];
struct node { vector<int> v; } st[4 * maxn];

void build(int k = 1, int l = 1, int r = n) {
  if (l == r) {
    st[k].v.push_back(a[l]);
  } else {
    build(L, l, M);
    build(R, M + 1, r);
    merge(st[L].v.begin(), st[L].v.end(), st[R].v.begin(), st[R].v.end(),
          back_inserter(st[k].v));
  }
}

// here, k in triple query is x
int qry(int i, int j, int x, int k = 1, int l = 1, int r = n) {
  if (r < i || j < l) { return 0; }
  if (i <= l && r <= j) return st[k].v.size() -
                                 (upper_bound(st[k].v.begin(), st[k].v.end(), x) - st[k].v.begin());
  return qry(i, j, x, L, l, M) + qry(i, j, x, R, M + 1, r);
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) { cin >> a[i]; }
  build();

  int ans = 0;
  cin >> q;
  while (q--) {
    int i, j, k;

    cin >> i >> j >> k;
    i = max(1, i ^ ans);
    j = min(n, j ^ ans);
    k ^= ans;

    if (i > j) { ans = 0; }
    else { ans = qry(i, j, k); }

    cout << ans << '\n';
  }

  return 0;
}
