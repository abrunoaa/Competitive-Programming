#include <bits/stdc++.h>
using namespace std;

#define maxn 200010
#define inf 0x3f3f3f3f
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

typedef long long ll;

char buf[100];
int n, m, v[maxn];
ll st[4 * maxn], lazy[4 * maxn];

bool read(int &i, int &j, int &k) {
  cin.getline(buf, 100);
  return sscanf(buf, "%d%d%d", &i, &j, &k) == 3;
}

ll build(int k = 1, int l = 0, int r = n - 1) {
  if (l == r) { return st[k] = v[l]; }
  return st[k] = min(build(L, l, M), build(R, M + 1, r));
}

void prop(int k) {
  ll &l = lazy[k];
  if (l) {
    st[k] += l;
    if (R < 4 * maxn) {
      lazy[L] += l;
      lazy[R] += l;
    }
    l = 0;
  }
}

ll upd(int i, int j, int v, int k = 1, int l = 0, int r = n - 1) {
  prop(k);
  if (r < i || j < l) { return st[k]; }
  if (i <= l && r <= j) { return st[k] + (lazy[k] = v); }
  return st[k] = min(upd(i, j, v, L, l, M), upd(i, j, v, R, M + 1, r));
}

ll qry(int i, int j, int k = 1, int l = 0, int r = n - 1) {
  if (r < i || j < l) { return inf; }
  prop(k);
  if (i <= l && r <= j) { return st[k]; }
  return min(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

void inc(int i, int j, int k) {
  if (i <= j) { upd(i, j, k); }
  else { upd(i, n - 1, k), upd(0, j, k); }
}

ll rmq(int i, int j) {
  if (i <= j) { return qry(i, j); }
  return min(qry(i, n - 1), qry(0, j));
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) { cin >> v[i]; }
  cin >> m, cin.ignore();

  build();
  while (m--) {
    int i, j, k;
    if (read(i, j, k)) { inc(i, j, k); }
    else { cout << rmq(i, j) << '\n'; }
  }

  return 0;
}
