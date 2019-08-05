#include <bits/stdc++.h>
using namespace std;

#define maxn 10010
#define mod 1000000007

int a[maxn];
vector<int> C[maxn];

void pascal() {
  for (int i = 0; i < maxn; ++i) {
    C[i].resize(i + 1);
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  pascal();

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sort(a, a + n);
    int ans = 0;
    for (int i = k - 1; i < n; ++i) {
      ans = (ans + (long long)a[i] * C[i][k - 1]) % mod;
    }
    cout << "Case #" << t << ": " << ans << '\n';
  }

  return 0;
}
