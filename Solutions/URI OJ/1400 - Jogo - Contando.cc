#include <bits/stdc++.h>
using namespace std;

bool palma(int x){
  if(x % 7 == 0) return 1;
  while(x){
    if(x % 10 == 7) return 1;
    x /= 10;
  }
  return 0;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m, k;
  while(cin >> n >> m >> k && (n || m || k)){
    for(int i = 1, j = 1, x; ; i += x, ++j){
      if(i == n){
        x = -1;
      }
      else if(i == 1){
        x = 1;
      }
      // cerr << " >> " << i << ' ' << j << ' ' << palma(i) << endl;
      if(i == m && palma(j) && --k == 0){
        cout << j << '\n';
        break;
      }
    }
  }

  return 0;
}
