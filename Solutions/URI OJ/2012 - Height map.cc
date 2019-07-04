#include <bits/stdc++.h>
using namespace std;

#define maxn 103

bool vis[maxn][maxn];
int r, c, v[maxn][maxn];

void ff(int i, int j){
  static const int I[] = { -1, 1, 0, 0 };
  static const int J[] = { 0, 0, -1, 1 };
  vis[i][j] = 1;
  for(int k = 0; k < 4; ++k){
    int x = i + I[k];
    int y = j + J[k];
    if(vis[x][y]) continue;
    if(v[i][j] != v[x][y]) continue;
    ff(x, y);
  }
}

/* [a b]
 * [c d] */
inline bool checkl(int a, int b, int c, int d){ return (c < a && c < b && d < a && d < b); }
inline bool checkg(int a, int b, int c, int d){ return (c > a && c > b && d > a && d > b); }

int main(){
  // assert(freopen("in","r",stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> r >> c;
  int ans = 5;
  for(int i = 1; i <= r; ++i){
    for(int j = 1; j <= c; ++j){
      cin >> v[i][j];
    }
  }
  for(int i = 2; i <= r; ++i){
    for(int j = 1; j <= c; ){
      if(v[i][j] == v[i - 1][j]){
        ++j;
      }
      else{
        auto cmp = v[i][j] < v[i - 1][j] ? checkl : checkg;
        while(++j, j <= c && cmp(v[i - 1][j - 1], v[i - 1][j], v[i][j - 1], v[i][j]));
        ++ans;
      }
    }
  }
  for(int j = 2; j <= c; ++j){
    for(int i = 1; i <= r; ){
      if(v[i][j] == v[i][j - 1]){
        ++i;
      }
      else{
        auto cmp = v[i][j] < v[i][j - 1] ? checkl : checkg;
        while(++i, i <= r && cmp(v[i][j - 1], v[i - 1][j - 1], v[i][j], v[i - 1][j]));
        ++ans;
      }
    }
  }
  for(int i = 1; i <= r; ++i){
    for(int j = 1; j <= c; ++j){
      if(!vis[i][j]){
        ff(i, j);
        ++ans;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
