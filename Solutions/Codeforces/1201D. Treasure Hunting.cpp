#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = (int)2e5 + 3;

int n, m, k, q;
int safe[maxn];
vector<int> treasure[maxn];
vector<int> up[maxn];
map<int,ll> best[maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> q;
  for (int i = 0; i < k; ++i) {
    int r, c;
    cin >> r >> c;
    treasure[r].push_back(c);
  }
  for (int i = 0; i < q; ++i) {
    cin >> safe[i];
  }
  sort(safe, safe + q);
  for (; treasure[n].empty(); --n);
  int n2 = 0, last = 0;
  for (int i = 1; i <= n; ++i) {
    if (!treasure[i].empty()) {
      if (i != ++n2) {
        treasure[n2] = move(treasure[i]);
      }
      last = i;
    }
  }
  n = n2;
  ll climb = last - 1;
  for (int i = 1; i <= n; ++i) {
    auto& t = treasure[i];
    sort(t.begin(), t.end());
    auto add = [i](int p) {
      int r = (int)(upper_bound(safe, safe + q, p) - safe - 1);
      if (r != -1 && safe[r] == p) {
        up[i].push_back(safe[r]);
      } else {
        if (r != -1) up[i].push_back(safe[r]);
        if (r + 1 != q) up[i].push_back(safe[r + 1]);
      }
    };
    add(t[0]);
    if (t.size() > 1) {
      add(t.back());
    }
  }
  if (n == 1) {
    cout << climb + treasure[1].back() - 1 << '\n';
    return 0;
  }
  for (int u = 0; u < (int)up[n].size(); ++u) {
    int a = treasure[n][0];
    int b = treasure[n].back();
    int l = abs(up[n][u] - a);
    int r = abs(up[n][u] - b);
    best[n][u] = min(l, r) + b - a;
  }
  for (int i = n - 1; i > 1; --i) {
    int a = treasure[i][0];
    int b = treasure[i].back();
    for (int u = 0; u < (int)up[i].size(); ++u) {
      auto& ref = best[i][u] = (ll)1e18;
      for (int v = 0; v < (int)up[i + 1].size(); ++v) {
        int l = abs(up[i][u] - a) + abs(b - up[i + 1][v]);
        int r = abs(up[i][u] - b) + abs(a - up[i + 1][v]);
        ref = min(ref, min(l, r) + b - a + best[i + 1][v]);
      }
    }
  }
  ll ans = (ll)1e18;
  if (treasure[1].empty()) {
    for (int u : up[2]) {
      ans = min(ans, u - 1 + best[2][u]);
    }
  } else {
    int b = treasure[1].back();
    for (int u = 0; u < (int)up[2].size(); ++u) {
      ll tmp = b - 1 + abs(b - up[2][u]) + best[2][u];
      ans = min(ans, tmp);
    }
  }
  cout << climb + ans << '\n';
  return 0;
}
