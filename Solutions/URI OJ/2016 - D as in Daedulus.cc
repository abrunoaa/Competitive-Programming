#include <bits/stdc++.h>
using namespace std;

int main(){
  // assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for(int i = 0; i < m; ++i){
    int b, c;
    cin >> b >> c;
    int s = 0;
    for(int j = 1; j < n; ++j){
      int x;
      cin >> x;
      s += x;
    }
    int d;
    for(d = 1; d <= 10000 && d + s <= b; d *= 10);
    d /= 10;
    if(d < c){
      ans += d;
    }
    else{
      ans += d - c;
    }
  }
  cout << ans << '\n';
  return 0;
}
