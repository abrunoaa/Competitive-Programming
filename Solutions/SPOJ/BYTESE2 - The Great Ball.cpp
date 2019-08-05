#include <bits/stdc++.h>
using namespace std;

#define maxn 110

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t, n, in[maxn], out[maxn], sum[2 * maxn];
  map<int, int> time;

  cin >> t;
  while (t--) {
    memset(sum, 0, sizeof sum);
    time.clear();

    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> in[i] >> out[i];
      time[ in[i] ];
      time[ out[i] ];
    }

    int cnt = 0;
    for (auto &x : time) { x.second = ++cnt; }

    for (int i = 0; i < n; ++i) {
      ++sum[ time[ in[i] ] ];
      --sum[ time[ out[i] ] + 1 ];
    }

    int ans = 0;
    for (int k = 1; k <= 2 * n; ++k) {
      sum[k] += sum[k - 1];
      ans = max(ans, sum[k]);
    }
    cout << ans << '\n';
  }

  return 0;
}
