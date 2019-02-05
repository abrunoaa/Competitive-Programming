#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

int g, c[12], n[12], cortes[1010];

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  while(cin >> g && g){
    for(int i = 0; i < g; ++i){
      cin >> c[i];
    }
    for(int i = 0; i < g; ++i){
      cin >> n[i];
    }

    memset(cortes, inf, sizeof cortes);
    cortes[100] = 0;
    queue<int> q;
    q.push(100);
    while(!q.empty()){
      int cab = q.front();
      q.pop();

      // cerr << " >> " << cab << endl;
      if(cab == 0){
        goto exit;
      }
      for(int i = 0; i < g; ++i){
        if(cab >= c[i]){
          if(cab == c[i]){
            cortes[0] = cortes[cab] + 1;
            goto exit;
          }
          if(cab - c[i] + n[i] <= 1000 && cortes[cab - c[i] + n[i]] == inf){
            cortes[cab - c[i] + n[i]] = cortes[cab] + 1;
            q.push(cab - c[i] + n[i]);
          }
        }
      }
    }

  exit:
    if(cortes[0] == inf){
      cout << "cavaleiro morreu\n";
    }
    else{
      cout << cortes[0] << '\n';
    }
  }

  return 0;
}
