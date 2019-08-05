#include <bits/stdc++.h>
using namespace std;

#define maxp 7994

bitset<maxp> isp;
int dp[maxp][4];
vector<int> p;

void sieve() {
  isp.set();
  isp[0] = isp[1] = 0;
  for (int i = 2; i < maxp; ++i) {
    if (isp[i]) {
      for (int j = i * i; j < maxp; j += i) {
        isp[j] = 0;
      }
      int u = (int)sqrt(i);
      for (int a = 0; a <= u; ++a) {
        int b = (int)sqrt(i - a * a);
        if (a * a + b * b == i) {
          p.push_back(i);
          break;
        }
      }
    }
  }
}

void calc() {
  for (int k = 1; k <= 3; ++k) {
    dp[0][k] = 1;
  }
  for (int s = 1; s < maxp; ++s) {
    for (int k = 1; k <= 3; ++k) {
      dp[s][k] = dp[s][k - 1] + (s < k ? 0 : dp[s - k][k]);
    }
  }
}

int main() {
  sieve();
  calc();
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << dp[p[n - 1]][k] << '\n';
  }
  return 0;
}
