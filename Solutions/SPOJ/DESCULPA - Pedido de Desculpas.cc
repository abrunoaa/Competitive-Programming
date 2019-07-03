#include <bits/stdc++.h>
using namespace std;

int dp[1003];

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  int ct = 0;
  int n, m;
  while(cin >> m >> n && (m || n)){
    memset(dp, 0, (m + 1) * sizeof(dp[0]));
    for(int i = 0; i < n; ++i){
      int v, w;
      cin >> w >> v;
      for(int j = m; j >= w; --j){
        dp[j] = max(dp[j], dp[j - w] + v);
      }
    }
    cout << "Teste " << ++ct << '\n';
    cout << dp[m] << "\n\n";
  }
  return 0;
}
