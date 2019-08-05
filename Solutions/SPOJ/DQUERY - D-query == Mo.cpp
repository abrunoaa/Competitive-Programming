#include <bits/stdc++.h>
using namespace std;

#define maxn 30010
#define maxq 200010
#define st first
#define nd second

typedef pair<int, int> ii;
typedef pair<ii, int> tri;

int N, Q, v[maxn], current = 0, ans[maxq], f[1000010];
tri q[maxq];

inline void add(int k) { if (++f[k] == 1) ++current; }
inline void rem(int k) { if (--f[k] == 0) --current; }

void mo() {
  int bs = sqrt(N);
  sort(q, q + Q, [bs](const tri & x, const tri & y) {
    int bx = x.st.st / bs, by = y.st.st / bs;
    return bx != by ? bx < by : x.st.nd < y.st.nd;
  });

  int mol = 1, mor = 0;
  for (int i = 0; i < Q; ++i) {
    int l = q[i].st.st;
    int r = q[i].st.nd;

    while (mor < r) { add(v[++mor]); }
    while (mor > r) { rem(v[mor--]); }
    while (mol < l) { rem(v[mol++]); }
    while (mol > l) { add(v[--mol]); }

    ans[ q[i].nd ] = current;
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) { cin >> v[i]; }
  cin >> Q;
  for (int i = 0, x, y; i < Q; ++i) {
    cin >> x >> y;
    q[i] = tri(ii(x, y), i);
  }

  mo();
  for (int i = 0; i < Q; ++i) { cout << ans[i] << '\n'; }

  return 0;
}
