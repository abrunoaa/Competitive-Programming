#include <bits/stdc++.h>
using namespace std;

#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

typedef vector<int> vi;

const int maxn = (int)1e5 + 3;

int n, q, x[maxn];
int idx[maxn];
vi st[4 * maxn];
vi freq[maxn];

vi& build(int t = 1, int l = 1, int r = n) {
  if (l == r) {
    st[t] = {idx[l]};
  } else {
    auto a = build(L, l, M);
    auto b = build(R, M+1, r);
    st[t].resize(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), st[t].begin());
  }
  return st[t];
}

int qry(int i, int j, int k, int t = 1, int l = 1, int r = n) {
  if (l == r) return l;
  int nl = (int)(upper_bound(st[L].begin(), st[L].end(), j) - lower_bound(st[L].begin(), st[L].end(), i));
  if (nl >= k) return qry(i, j, k, L, l, M);
  return qry(i, j, k - nl, R, M+1, r);
}

int main() {
  assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  map<int,int> mp;
  for (int i = 1, c = 0; i <= n; ++i) {
    cin >> x[i];
    idx[i] = i;
    int &m = mp[x[i]];
    if (!m) m = ++c;
    freq[m].push_back(i);
  }
  sort(idx + 1, idx + n + 1, [](int i, int j){
    return x[i] < x[j];
  });
  build();
  while (q--) {
    int l, r, k, g, d;
    cin >> l >> r >> k >> g >> d;
    int pos = qry(l, r, k);
    int y = x[idx[pos]];
    int m = mp[y];
    int ans = (int)(upper_bound(freq[m].begin(), freq[m].end(), r) - lower_bound(freq[m].begin(), freq[m].end(), l));
    g = abs(g - ans);
    d = abs(d - ans);
    char win = g == d ? 'E' : g < d ? 'G' : 'D';
    cout << y << ' ' << ans << ' ' << win << '\n';
  }
  return 0;
}
