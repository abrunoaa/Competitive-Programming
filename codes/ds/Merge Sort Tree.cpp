#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)
#define ub(v, x) (int)(upper_bound(v.begin(), v.end(), x) - v.begin())
#define lb(v, x) (int)(lower_bound(v.begin(), v.end(), x) - v.begin())

typedef vector<int> vi;

const int maxn = 100003;

int n, v[maxn];
vi st[4 * maxn];

void merge(vi& dest, const vi& x, const vi& y) {
  dest.resize(x.size() + y.size());
  merge(x.begin(), x.end(), y.begin(), y.end(), dest.begin());
}

vi& build(int t = 1, int l = 0, int r = n - 1) {
  if (l == r) st[t] = {v[l]};
  else merge(st[t], build(L, l, M), build(R, M + 1, r));
  return st[t];
}

// returns #values < x
int qry(int i, int j, int x, int t = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) return 0;
  if (i <= l && r <= j) return lb(st[t], x);                // upper_bound for <= x
  return qry(i, j, x, L, l, M) + qry(i, j, x, R, M + 1, r);
}

// find the k-th number of a range [l, r] if it was sorted:
//  * create an index array sorted by value: index.sort((i, j) -> value[i] < value[j])
//  * build the tree using those indexes
//  * do the following query
int kth(int i, int j, int k, int t = 1, int l = 0, int r = n - 1) {
  if (l == r) return st[t][0];
  int nl = ub(st[R], j) - lb(st[L], i);       // #indexes inside range [i, j]
  if (k <= nl) return kth(i, j, k, L, l, M);  // the lowest values are in the left tree
  return kth(i, j, k - nl, R, M + 1, r);
}
/** end ***********************************************************************/

int main() {
  return 0;
}
