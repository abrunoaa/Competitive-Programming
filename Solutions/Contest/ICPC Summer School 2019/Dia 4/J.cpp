#include <bits/stdc++.h>
using namespace std;

typedef int Int;

#define maxn 200003
#define inf 0x3f3f3f3f3f3f3f3f
#define st first
#define nd second
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)
#define int long long

typedef pair<int, int> ii;
struct tri { int st, nd, rd; };

struct Qry {
  int a, b, i;
  bool operator < (const Qry &q) const { return b < q.b; }
};

int n, t, h[maxn], ans[maxn], st[4 * maxn], lz[4 * maxn];
vector<Qry> q1, q2;

void prop(int t, int n) {
  int &x = lz[t];
  if (x) {
    st[t] = x * n;
    if (n > 1) { lz[L] = lz[R] = x; }
    x = 0;
  }
}

int qry(int i, int j, int t = 1, int l = 1, int r = n) {
  if (r < i || j < l) { return 0; }
  prop(t, r - l + 1);
  if (i <= l && r <= j) { return st[t]; }
  return qry(i, j, L, l, M) + qry(i, j, R, M + 1, r);
}

int upd(int i, int j, int x, int t = 1, int l = 1, int r = n) {
  if (i <= l && r <= j) {
    lz[t] = x;
    prop(t, r - l + 1);
    return st[t];
  }
  prop(t, r - l + 1);
  if (r < i || j < l) { return st[t]; }
  return st[t] = upd(i, j, x, L, l, M) + upd(i, j, x, R, M + 1, r);
}

void proccess(vector<Qry> &q) {
  sort(q.begin(), q.end());
  vector<tri> p;
  p.push_back({inf, 0, 0});
  memset(st, 0, sizeof st);
  memset(lz, 0, sizeof lz);
  for (int i = 1, j = 0; ; ++i) {
    // cerr << " >> " << p.back().st << ' ' << p.back().nd << ' ' << p.back().rd << " -- " << q[j].b << endl;
    for (; j < (int)q.size() && q[j].b == i; ++j) {
      int a = lower_bound(p.begin(), p.end(), q[j].a, [](const tri & x, int y) { return x.rd < y; }) - p.begin();
      ans[q[j].i] = qry(p[a - 1].rd + 1, i);
      // cerr << " -- " << a << ' ' << p[a-1].rd << " == " << ans[q[j].i] << endl;
    }
    if (i == n) { break; }
    int k = 1;
    while (h[i] > p.back().st) {
      k += p.back().nd;
      p.pop_back();
    }
    p.push_back({h[i], k, i});
    upd(i - k + 1, i, h[i]);
  }
}

Int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) { cin >> h[i]; }
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    if (a < b) q1.push_back({a, b, i});
    else q2.push_back({n - a + 1, n - b + 1, i});
  }
  proccess(q1);
  reverse(h + 1, h + n);
  proccess(q2);
  for (int i = 0; i < t; ++i) { cout << ans[i] << '\n'; }
  return 0;
}
