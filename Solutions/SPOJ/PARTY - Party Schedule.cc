#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int,int> ii;

ii dp[503];

inline void setBest(ii& x, const ii& y){
  if(x.st < y.st || (x.st == y.st && x.nd > y.nd)){
    x = y;
  }
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  int n, m;
  while(cin >> m >> n && (m || n)){
    memset(dp, 0, (m + 1) * sizeof(dp[0]));
    for(int i = 0; i < n; ++i){
      int w, v;
      cin >> w >> v;
      for(int j = m; j >= w; --j){
        ii tmp = dp[j - w];
        tmp.st += v;
        tmp.nd += w;
        setBest(dp[j], tmp);
      }
    }
    cout << dp[m].nd << ' ' << dp[m].st << '\n';
  }
  return 0;
}
