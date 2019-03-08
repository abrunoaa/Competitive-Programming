#include <bits/stdc++.h>
using namespace std;

#define maxn 1010

vector<int> ans[maxn];

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  // freopen("in","r",stdin);

  int n, k, d;
  cin >> n >> k >> d;

  ans[0].assign(d, 1);
  for(int i = 1, j; i < n; ++i){
    ans[i] = ans[i - 1];
    for(j = d - 1; ++ans[i][j] > k && j > 0; --j){
      ans[i][j] = 1;
    }
    if(ans[i][j] > k){
      cout << "-1\n";
      return 0;
    }
  }

  for(int j = 0; j < d; ++j)
    for(int i = 0; i < n; ++i)
      cout << ans[i][j] << " \n"[i == n-1];

  return 0;
}
