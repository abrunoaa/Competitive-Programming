#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 100010

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

typedef long long ll;

struct no {
  ll sqsum;
  int sum;
  int add, set;
};

int n, q, a[maxn];
no st[4 * maxn];

no merge(const no &x, const no &y) {
  return no{ x.sqsum + y.sqsum, x.sum + y.sum, 0, inf };
}

void prop(int k, int nk) {
  if (st[k].set != inf) {
    auto s = st[k].set;
    st[k].sum = nk * s;
    st[k].sqsum = (ll)nk * s * s;
    st[k].add = 0;
    st[k].set = inf;
  } else if (st[k].add) {
    /*
     * a1² + a2² + a3² = sqSum
     * (a1 + x)² + (a2 + x)² + (a3 + x)² = sqSum + d
     * ---> d = 3x² + 2x * (a1 + a2 + a3)
     */
    auto x = st[k].add;
    st[k].sqsum += (ll)nk * x * x + 2ll * x * st[k].sum;
    st[k].sum += nk * x;
    st[k].add = 0;
  }
}

no build(int k = 1, int l = 1, int r = n) {
  if (l == r) return st[k] = no{ a[l]* a[l], a[l], 0, inf };
  return st[k] = merge(build(L, l, M), build(R, M + 1, r));
}

no add(int i, int j, int x, int k = 1, int l = 1, int r = n) {
  prop(k, r - l + 1);
  if (r < i || j < l) { return st[k]; }
  if (i <= l && r <= j) {
    st[k].add += x;
    prop(k, r - l + 1);
    return st[k];
  }
  return st[k] = merge(add(i, j, x, L, l, M), add(i, j, x, R, M + 1, r));
}

no upd(int i, int j, int x, int k = 1, int l = 1, int r = n) {
  prop(k, r - l + 1);
  if (r < i || j < l) { return st[k]; }
  if (i <= l && r <= j) {
    st[k].set = x;
    prop(k, r - l + 1);
    return st[k];
  }
  return st[k] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M + 1, r));
}

ll qry(int i, int j, int k = 1, int l = 1, int r = n) {
  if (r < i || j < l) { return 0; }
  prop(k, r - l + 1);
  if (i <= l && r <= j) { return st[k].sqsum; }
  return qry(i, j, L, l, M) + qry(i, j, R, M + 1, r);
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case " << t << ":\n";

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }

    build();
    while (q--) {
      int op, l, r, x;
      cin >> op >> l >> r;
      if (op == 2) {
        cout << qry(l, r) << '\n';
      } else {
        cin >> x;
        if (op == 1) {
          add(l, r, x);
        } else {
          upd(l, r, x);
        }
      }
    }
  }

  return 0;
}
