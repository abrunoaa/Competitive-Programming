#include <bits/stdc++.h>
using namespace std;

#define maxn 30010
#define maxq 200010
#define st first
#define nd second

typedef pair<int, int> ii;

struct query { int i, j, k, id; } q[maxq];

int N, Q, bit[maxn], ans[maxq];
ii v[maxn];

void upd(int i, int x) { for (; i <= N; i += i & -i) bit[i] += x; }

int qry(int i) {
  int s = 0;
  for (; i; i -= i & -i) { s += bit[i]; }
  return s;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1, x; i <= N; ++i) {
    cin >> x;
    v[i] = ii(x, i);
  }
  cin >> Q;
  for (int i = 0, x, y, z; i < Q; ++i) {
    cin >> x >> y >> z;
    q[i] = { x, y, z, i };
  }

  sort(v + 1, v + 1 + N);
  sort(q, q + Q, [](const query & x, const query & y) { return x.k > y.k; });

  for (int i = 0, j = N; i < Q; ++i) {
    for (; j && v[j].st > q[i].k; --j) {
      upd(v[j].nd, +1);
    }
    ans[ q[i].id ] = qry(q[i].j) - qry(q[i].i - 1);
  }
  for (int i = 0; i < Q; ++i) { cout << ans[i] << '\n'; }

  return 0;
}
