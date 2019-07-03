#include <bits/stdc++.h>
using namespace std;

int dp[int(2e6 + 3)];

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> k >> n;
  for(int i = 0; i < n; ++i){
    int v, w;
    cin >> v >> w;
    for(int j = k; j >= w; --j){
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }
  cout << dp[k] << '\n';
  return 0;
}
