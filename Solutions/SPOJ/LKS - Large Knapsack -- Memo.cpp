#include <bits/stdc++.h>
using namespace std;

#define maxn 503

int n, k;
int v[maxn], w[maxn];
map<int, int> memo[maxn];

int ks(int i, int disp) {
  if (i == n || w == 0) { return 0; }
  if (memo[i].count(disp)) { return memo[i][disp]; }
  int &dp = memo[i][disp] = ks(i + 1, disp);
  if (w[i] <= disp) { dp = max(dp, ks(i + 1, disp - w[i]) + v[i]); }
  return dp;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> k >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> w[i];
  }
  cout << ks(0, k) << '\n';
  return 0;
}
