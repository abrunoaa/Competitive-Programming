#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define maxn 100010
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;

struct no { ll x, best, lazy, lazymax; } st[4 * maxn];
int n, m, v[maxn];
ll ans[maxn];
tri q[maxn];

no merge(const no &x, const no &y) { return no{ max(x.x, y.x), max(x.best, y.best), 0, 0 }; }

void prop(int k) {
  ll &l = st[k].lazy;
  if (l) {
    ll &lm = st[k].lazymax;
    st[k].best = max(st[k].best, st[k].x + lm);
    st[k].x += l;
    if (R < 4 * maxn) {
      st[L].lazymax = max(st[L].lazymax, st[L].lazy + lm);
      st[L].lazy += l;
      st[R].lazymax = max(st[R].lazymax, st[R].lazy + lm);
      st[R].lazy += l;
    }
    lm = l = 0;
  }
}

no upd(int i, int j, int v, int k = 1, int l = 1, int r = n) {
  prop(k);
  if (r < i or j < l) { return st[k]; }
  if (i <= l and r <= j) {
    st[k].lazy += v;
    st[k].lazymax = max(st[k].lazymax, st[k].lazymax + v);
    prop(k);
    return st[k];
  }
  prop(k);
  return st[k] = merge(upd(i, j, v, L, l, M), upd(i, j, v, R, M + 1, r));
}

no qry(int i, int j, int k = 1, int l = 1, int r = n) {
  if (r < i or j < l) return no{ 0, 0, 0, 0 };
  prop(k);
  if (i <= l and r <= j) { return st[k]; }
  return merge(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) { cin >> v[i]; }
  cin >> m;
  for (int i = 0, x, y; i < m; ++i) {
    cin >> x >> y;
    q[i] = tri(ii(x, y), i);
  }
  sort(q, q + m, [](const tri & x, const tri & y) { return x.st.nd < y.st.nd; });

  map<int, int> last;
  for (int i = 1, k = 0; i <= n; ++i) {
    int &l = last[ v[i] ];
    upd(l + 1, i, v[i]);
    l = i;
    for (; k < m && q[k].st.nd == i; ++k) {
      ans[ q[k].nd ] = qry(q[k].st.st, q[k].st.nd).best;
    }
  }
  for (int i = 0; i < m; ++i) { cout << ans[i] << '\n'; }

  return 0;
}
