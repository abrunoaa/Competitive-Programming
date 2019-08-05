#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)
#define pb push_back

typedef pair<int, int> ii;

int n, m, u[maxn];
ii v[maxn];
vector<int> st[4 * maxn];

void build(int k = 1, int l = 1, int r = n) {
  if (l == r) {
    st[k].pb(v[l].second);
  } else {
    build(L, l, M);
    build(R, M + 1, r);
    merge(st[L].begin(), st[L].end(), st[R].begin(), st[R].end(), back_inserter(st[k]));
  }
}

int qry(int i, int j, int kth, int k = 1, int l = 1, int r = n) {
  if (l == r) { return u[ st[k][0] ]; }

  int pi = lower_bound(st[L].begin(), st[L].end(), i) - st[L].begin();
  int pj = upper_bound(st[L].begin(), st[L].end(), j) - st[L].begin();
  int diff = pj - pi;

  if (kth > diff) { return qry(i, j, kth - diff, R, M + 1, r); }
  return qry(i, j, kth, L, l, M);
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> u[i];
    v[i] = ii(u[i], i);
  }
  sort(v + 1, v + 1 + n);
  build();
  while (m--) {
    int i, j, k;
    cin >> i >> j >> k;
    cout << qry(i, j, k) << '\n';
  }

  return 0;
}
