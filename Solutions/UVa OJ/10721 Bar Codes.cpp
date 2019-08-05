#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, n, m;
ll dp[51][51][51];

ll code (int id, int q, int diff) {
  if (id > n || diff > k) { return 0; }                   // extrapolou

  // dp
  ll &ref = dp[id][q][diff];
  if (ref != -1) { return ref; }

  if (id == n && diff == k) { return ref = 1; }           // chegou ao fim: achou
  if (q == m) { return ref = code(id + 1, 1, diff + 1); } // apenas ignora esta cor

  // aceita + ignora esta cor
  return ref = code(id + 1, q + 1, diff) + code(id + 1, 1, diff + 1);
}

int main() {
  while (scanf("%d%d%d", &n, &k, &m) == 3) {
    memset(dp, -1, sizeof dp);
    printf("%lld\n", code(1, 1, 1));
  }

  return 0;
}
