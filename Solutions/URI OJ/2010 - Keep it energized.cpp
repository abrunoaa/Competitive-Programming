#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn int(1e5 + 3)

struct Shop {
  int l, s, c;
  bool operator < (const Shop &s) const {
    return l < s.l;
  }
};

int e[maxn], ft[maxn], dp[maxn];
vector<Shop> shop;

int findMin(int i) {
  int ans = inf;
  for (; i; i -= i & -i) {
    ans = min(ans, ft[i]);
  }
  return ans;
}

void updMin(int i, int x) {
  for (; i < maxn; i += i & -i) {
    ft[i] = min(ft[i], x);
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i];
    e[i] += e[i - 1];
  }
  for (int i = 0; i < m; ++i) {
    int l, s, c;
    cin >> l >> s >> c;
    shop.push_back({l, s, c});
  }
  sort(shop.begin(), shop.end());
  shop.push_back({n + 1, 0, 0});
  memset(ft, 63, sizeof(ft));
  memset(dp, 63, sizeof(dp));
  updMin(n + 1, 0);
  for (int i = m - 1; i >= 0; --i) {
    int l = shop[i].l;
    int k = (int)(upper_bound(e, e + n + 1, shop[i].s, [l](int sch, int elem) {
      return elem - e[l - 1] > sch;
    }) - e);
    dp[l] = min(dp[l], findMin(k) + shop[i].c);
    updMin(l, dp[l]);
  }
  if (dp[1] == inf) {
    dp[1] = -1;
  }
  cout << dp[1] << '\n';
  return 0;
}
