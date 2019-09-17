#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = (int)2e5 + 3;

int pos[maxn];
int ft[maxn];

void upd(int i, int x) {
  for (++i; i; i -= i & -i) {
    ft[i] += x;
  }
}

int qry(int i) {
  int s = 0;
  for (++i; i < maxn; i += i & -i) {
    s += ft[i];
  }
  return s;
}

ll cross(auto &u, auto &v) {
  for (int i = 0; i < (int)u.size(); ++i) {
    pos[u[i]] = i;
  }
  memset(ft, 0, sizeof(ft));
  ll ans = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    ans += qry(pos[v[i]]);
    upd(pos[v[i]], +1);
  }
  return ans;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  for (int &x : c) cin >> x;
  ll rem = 0;
  rem += cross(a, b);
  rem += cross(a, c);
  rem += cross(b, c);
  cout << (ll)n * (n - 1) / 2 - rem / 2 << '\n';
  return 0;
}
