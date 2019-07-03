#include <bits/stdc++.h>
using namespace std;

int dp[50][160];

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  int c;
  cin >> c;
  while(c--){
    int t, a, n;
    cin >> t >> a >> n;
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; ++i){
      int x, y, z;
      cin >> x >> y >> z;
      for(int j = t; j >= 0; --j){
        for(int k = a; k >= 0; --k){
          dp[j][k] = min(dp[j][k], dp[max(0, j - x)][max(0, k - y)] + z);
        }
      }
    }
    cout << dp[t][a] << '\n';
  }
  return 0;
}
