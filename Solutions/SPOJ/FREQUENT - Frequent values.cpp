#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define st first
#define nd second
#define L (k << 1)
#define R (L + 1)
#define M ((l + r) >> 1)

typedef pair<int, int> ii;

int n, q, v[maxn], st[4 * maxn];
ii u[maxn];

int build(int k = 1, int l = 1, int r = n) {
  if (l == r) { return st[k] = u[l].nd - u[l].st + 1; }
  return st[k] = max(build(L, l, M), build(R, M + 1, r));
}

int qry(int i, int j, int k = 1, int l = 1, int r = n) {
  if (r < i || j < l) { return 0; }
  if (i <= l && r <= j) { return st[k]; }
  return max(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

int query(int i, int j) {
  if (i > j) { return 0; }
  return qry(i, j);
}

void pre_build() {
  v[n + 1] = -1e9;
  for (int i = 1, j; i <= n; i = j) {
    for (j = i + 1; v[j] == v[j - 1]; ++j);
    ii t = ii(i, j - 1);
    for (int k = i; k < j; ++k) { u[k] = t; }
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  while (cin >> n >> q && n) {
    for (int i = 1; i <= n; ++i) { cin >> v[i]; }

    pre_build();
    build();
    while (q--) {
      int i, j;
      cin >> i >> j;
      if (u[i] == u[j]) {
        cout << j - i + 1 << '\n';
      } else
        cout << max(query(u[i].nd + 1, u[j].st - 1),
                    max(u[i].nd - i + 1, j - u[j].st + 1)) << '\n';
    }
  }

  return 0;
}
