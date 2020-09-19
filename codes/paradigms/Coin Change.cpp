const int maxn = 101;
const int maxm = 1000001;
const int inf = 0x3f3f3f3f;

int n;
int v[maxn];
int memo[maxm];

void coinChange() {
  memo[0] = 0;
  for (int c = 1; c < maxm; ++c) {
    auto &dp = memo[c] = inf;
    for (int i = 0; i < n; ++i)
      if (c >= v[i])
        dp = min(dp, memo[c - v[i]] + 1);
  }
}
