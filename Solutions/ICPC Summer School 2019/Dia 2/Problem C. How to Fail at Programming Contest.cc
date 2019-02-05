#include <bits/stdc++.h>
using namespace std;

#define maxn 2003
#define st first
#define nd second

typedef pair<int,int> ii;

int n, m;
ii item[maxn], dp[maxn];

int main(){
  // freopen("in","r",stdin);
  cin >> n >> m;
  for(int i = 0; i < n; ++i) cin >> item[i].st >> item[i].nd;
  sort(item, item + n); // os pesos maiores dependem dos menores
  for(int j = 0; j <= m; ++j) dp[j] = ii(0, j);
  for(int i = 0; i < n; ++i){
    int t = item[i].st, p = item[i].nd;
    for(int j = m; j >= t; --j){
      ii r = dp[j - t];
      r.st += p;
      dp[j] = dp[j].nd >= t ? r : min(dp[j], r);
    }
  }
  cout << dp[m].st << '\n';
  return 0;
}
