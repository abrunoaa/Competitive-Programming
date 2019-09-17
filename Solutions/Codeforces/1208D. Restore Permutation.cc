#include <bits/stdc++.h>
using namespace std;

#define int long long
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

const int maxn = (int)2e5 + 3;
const int inf = 0x3f3f3f3f3f3f3f3f;

int n, s[maxn];
int a[maxn];
int st[4 * maxn];
int lz[4 * maxn];

int build(int t = 1, int l = 0, int r = n - 1) {
  if (l == r) return st[t] = s[l];
  return st[t] = min(build(L, l, M), build(R, M+1, r));
}

void prop(int t, bool child) {
  if (lz[t]) {
    if (child) {
      st[L] -= lz[t];
      st[R] -= lz[t];
      lz[L] += lz[t];
      lz[R] += lz[t];
    }
    lz[t] = 0;
  }
}

int upd(int i, int t, int l, int r) {
  if (l == r) return st[t] = inf;
  if (i <= M) return st[t] = min(upd(i, L, l, M), st[R]);
  return st[t] = min(st[L], upd(i, R, M+1, r));
}

int upd(int i, int j, int x, int t, int l, int r) {
  if (r < i || j < l) return st[t];
  if (i <= l && r <= j) {
    st[t] -= x;
    lz[t] += x;
    return st[t];
  }
  prop(t, r - l);
  return st[t] = min(upd(i, j, x, L, l, M), upd(i, j, x, R, M+1, r));
}

int qry(int t = 1, int l = 0, int r = n - 1) {
  prop(t, r - l);
  if (l == r) return l;
  if (st[R] != 0) return qry(L, l, M);
  return qry(R, M+1, r);
}

signed main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  build();
  for (int i = 0; i < n; ++i) {
    int k = qry();
    a[k] = i + 1;
    upd(k + 1, n - 1, i + 1, 1, 0, n - 1);
    upd(k, 1, 0, n - 1);
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  return 0;
}
