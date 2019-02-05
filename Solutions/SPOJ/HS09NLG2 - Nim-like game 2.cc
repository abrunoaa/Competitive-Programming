#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int v[4];
    cin >> v[0] >> v[1] >> v[2] >> v[3];

    int m = 1e9;
    for(int i = 0; i < 4; ++i){
      m = min(m, v[i]);
    }

    int ans[4] = {};
    for(int i = 0; i < 3; ++i){
      if(v[i] > m){
        for(int j = i + 1; j < 4; ++j){
          if(v[j] > m){
            ans[i] = v[i] - m;
            ans[j] = v[j] - m;
            goto stop;
          }
        }
      }
    }
    cout << "Robert wins.\n\n";
    continue;

  stop:
    cout << "Julia wins.\n";
    for(int i = 0; i < 4; ++i){
      if(i) cout << ' ';
      cout << ans[i];
    }
    cout << "\n\n";
  }

  return 0;
}
