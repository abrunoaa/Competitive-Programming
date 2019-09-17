#include <bits/stdc++.h>
using namespace std;

#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)
#define int long long

const int maxn = (int)1e6 + 3;
const int inf = 0x3f3f3f3f;

int len, a[maxn];
int st[4 * maxn];
int ans[maxn], add[maxn];

int build(int t = 1, int l = 0, int r = len - 1) {
  if (l == r) return st[t] = a[l];
  return st[t] = max(build(L, l, M), build(R, M+1, r));
}

int qry(int i, int j, int t = 1, int l = 0, int r = len - 1) {
  if (r < i || j < l) return -inf;
  if (i <= l && r <= j) return st[t];
  return max(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

signed main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int n, w;
  cin >> n >> w;
  while (n--) {
    cin >> len;
    for (int i = 0; i < len; ++i) {
      cin >> a[i];
    }
    if (len < w - len) {
      int best = 0;
      for (int i = 0; i < len; ++i) {
        best = max(best, a[i]);
      }
      add[len] += best;
      add[w - len] -= best;
    }
    build();
    for (int i = 0; i < len; ++i) {
      int x = qry(max((int)0, i - (w - len)), i);
      if (i < w - len) {
        x = max(x, (int)0);
      }
      ans[i] += x;
    }
    for (int i = max(len, w - len); i < w; ++i) {
      int x = qry(i - (w - len), min(w - 1, i + (w - len)) - (w - len));
      ans[i] += max(x, (int)0);
    }
  }
  for (int i = 0; i < w; ++i) {
    if (i) add[i] += add[i - 1];
    cout << ans[i] + add[i] << ' ';
  }
  cout << '\n';
  return 0;
}
