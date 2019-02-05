#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int x, y;
  while(cin >> x >> y){
    cout << x << ' ' << y << ' ';
    if(x > y){
      swap(x, y);
    }

    int ans = 0;
    for(int k = x; k <= y; ++k){
      int qtd = 1;
      for(int n = k; n > 1; n = (n % 2 == 0 ? n / 2 : 3 * n + 1)){
        ++qtd;
      }
      ans = max(ans, qtd);
    }

    cout << ans << '\n';
  }

  return 0;
}
