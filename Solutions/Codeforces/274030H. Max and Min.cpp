#include <bits/stdc++.h>
using namespace std;

#define clz __builtin_clzll
#define lg(x) (63 - clz(x))

const int maxn = (int)2e4 + 3;

int n, m;
int a[maxn];
int dp[103][maxn];
int st1[maxn][lg(maxn) + 1];
int st2[maxn][lg(maxn) + 1];

void build() {
  for (int i = 0; i < n; ++i)
    st1[i][0] = st2[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 0; i + (1 << j) <= n; ++i) {
      st1[i][j] = min(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
      st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
    }
}

int qry(int i, int j) {
  // assert(i <= j);
  int k = lg(j - i + 1);
  // cerr << " && " << i << ' ' << j << ' ' << k << " == " << max(st2[i][k], st2[j - (1 << k) + 1][k]) << ' ' << min(st1[i][k], st1[j - (1 << k) + 1][k]) << endl;
  return max(st2[i][k], st2[j - (1 << k) + 1][k])
        -min(st1[i][k], st1[j - (1 << k) + 1][k]);
}

void solve(int i, int l, int r, int optl, int optr) {
  if (l > r) return;
  // cerr << " >> " << i << ' ' << l << ' ' << r << ' ' << optl << ' ' << optr << endl;
  int j = (l + r) / 2;
  if (j + 1 < i) {
    dp[i][j] = -1e9;
    solve(i, l, j - 1, optl, optr);
    solve(i, j + 1, r, optl, optr);
    return;
  }

  int best = -1;
  dp[i][j] = -1e9;
  for (int k = optl; k <= min(j, optr); ++k) {
    // cerr << " -- " << k << ' ' << j << ' ' << (k == 0 ? -(int)1e9 : dp[i - 1][k - 1]) << ' ' << qry(k, j) << endl;
    int tmp = (k == 0 ? -(int)1e9 : dp[i - 1][k - 1]) + qry(k, j);
    if (tmp > dp[i][j]) {
      dp[i][j] = tmp;
      best = k;
    }
  }
  // cerr << " ## " << i << ' ' << j << " == " << dp[i][j] << ' ' << best << endl;
  // assert(optl <= best);
  // assert(best <= optr);
  // assert(l <= j);
  // assert(j <= r);
  solve(i, l, j - 1, optl, best);
  solve(i, j + 1, r, best, optr);
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  build();
  int mx = -1e9;
  int mn = 1e9;
  for (int i = 0; i < n; ++i) {
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
    dp[1][i] = mx - mn;
  }
  for (int i = 2; i <= m; ++i) {
    solve(i, 0, n - 1, 0, n - 1);
  }
  cout << dp[m][n - 1] << '\n';
  return 0;
}
