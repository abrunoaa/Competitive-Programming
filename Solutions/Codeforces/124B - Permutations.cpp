#include <bits/stdc++.h>
using namespace std;

int n, k, ans, num[10];
string s[10];

void f(int mask){
  if(!mask){
    int l = num[0], u = num[0];
    for(int i = 1; i < n; ++i){
      if(num[i] < l){
        l = num[i];
      }
      else if(num[i] > u){
        u = num[i];
      }
    }
    ans = min(ans, u - l);
    return;
  }
  for(int i = 0; i < k; ++i){
    if((1 << i) & mask){
      for(int j = 0; j < n; ++j){
        num[j] = 10 * num[j] + s[j][i] - '0';
      }
      f(mask & ~(1 << i));
      for(int j = 0; j < n; ++j){
        num[j] /= 10;
      }
    }
  }
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while(cin >> n >> k){
    for(int i = 0; i < n; ++i){
      cin >> s[i];
      s[i].insert(s[i].begin(), k - s[i].size(), '0');
    }
    ans = 1e9;
    memset(num, 0, sizeof num);
    f((1 << k) - 1);
    cout << ans << '\n';
  }

  return 0;
}
