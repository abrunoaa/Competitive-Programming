#include <bits/stdc++.h>
using namespace std;

#define maxn 305010

int n, m, v[maxn];

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

again:
  while(cin >> n){
    for(int i = 0; i < n; ++i){
      cin >> v[i];
    }
    cin >> m;

    int x = lower_bound(v, v + n, m) - v + 1;
    if(v[x - 1] != m){
      cout << "N\n";
      goto again;
    }
    for(int k = 2; k <= x; ++k){
      if(x % k == 0){
        cout << "N\n";
        goto again;
      }
      // cerr << " >> " << x << ' ' << x / k << endl;
      x -= x / k;
    }
    cout << "Y\n";
  }

  return 0;
}
