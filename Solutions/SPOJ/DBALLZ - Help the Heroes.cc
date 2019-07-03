#include <bits/stdc++.h>
using namespace std;

int v[1003];
int w[1003];
int dp[int(1e6 + 3)];

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> m >> n;
    for(int i = 0; i < n; ++i){
      cin >> w[i];
    }
    for(int i = 0; i < n; ++i){
      cin >> v[i];
    }
    memset(dp, 0, (m + 1) * sizeof(dp[0]));
    for(int i = 0; i < n; ++i){
      int w = ::w[i];
      int v = ::v[i];
      for(int j = w; j <= m; ++j){
        dp[j] = max(dp[j], dp[j - w] + v);
      }
    }
    cout << dp[m] << '\n';
  }
  return 0;
}
