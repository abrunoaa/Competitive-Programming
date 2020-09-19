int n, a[maxn];

// can be modeled as knapsack with bounded weight: O(n * max(a))

/******************************************************************************/
bool subsetSum(int t) {               // O(n * t)
  vector<bool> dp(t + 1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = a[i]; j <= t; ++j)
      dp[j] = dp[j] | dp[j - a[i]];
  return dp[t];
}

/******************************************************************************/
#define setdp(i) dp[i / 64] |= 1ll << (i % 64)
#define getdp(i) ((dp[i / 64] >> (i % 64)) & 1)

bool subsetSum(int t) {               // O(n * t / 64) if t is big enough (~640)
  vector<long long> dp(t / 64 + 1);
  setdp(0);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    for (; x < 64; x += a[i]) setdp(x);
    int d = x / 64;
    int r = x % 64;
    dp[d] |= dp[0] << r;
    for (int j = d + 1; j <= t / 64; ++j)
      dp[j] |= (dp[j - d] << r) | ((dp[j - d - 1] >> (64 - r)) & ((1ll << r) - 1));
  }
  return getdp(t);
}
