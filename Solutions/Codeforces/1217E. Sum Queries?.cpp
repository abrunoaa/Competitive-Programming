#include <bits/stdc++.h>
using namespace std;

#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

const int inf = (int)2e9;
const int maxn = (int)2e5 + 3;
const int p10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

struct No {
  int ans, d[10];

  No(int x = 0) {
    ans = inf;
    for (int i = 0; i < 10; ++i) {
      d[i] = x / p10[i] % 10 != 0 ? x : inf;
    }
  }

  No operator+(const No& n) const {
    No tmp;
    tmp.ans = min(ans, n.ans);
    for (int i = 0; i < 10; ++i) {
      tmp.d[i] = min(d[i], n.d[i]);
      if (d[i] != inf && n.d[i] != inf) {
        tmp.ans = min(tmp.ans, d[i] + n.d[i]);
      }
    }
    return tmp;
  }
};

int n, a[maxn];
No st[4 * maxn];

No &build(int t = 1, int l = 1, int r = n) {
  if (l == r) return st[t] = No(a[l]);
  return st[t] = build(L, l, M) + build(R, M+1, r);
}

No qry(int i, int j, int t = 1, int l = 1, int r = n) {
  if (r < i || j < l) return No();
  if (i <= l && r <= j) return st[t];
  auto tmp = qry(i, j, L, l, M) + qry(i, j, R, M+1, r);
  return tmp;
}

No &upd(int i, int x, int t = 1, int l = 1, int r = n) {
  if (l == r) return st[t] = No(x);
  if (i <= M) return st[t] = upd(i, x, L, l, M) + st[R];
  return st[t] = st[L] + upd(i, x, R, M+1, r);
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build();
  while (m--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      upd(x, y);
    } else {
      int ans = qry(x, y).ans;
      cout << (ans == inf ? -1 : ans) << '\n';
    }
  }
  return 0;
}
