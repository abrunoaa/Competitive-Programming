#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

int pos[10], col[10];
int memo[8][8][12][(1 << 8) + 10];

inline bool check(int x, int y){
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int f(int l, int c, int p, int bm){
  if(!check(l, c)) return inf;

  int& pd = memo[l][c][p][bm];
  if(pd != -1) return pd;
  pd = inf;

  for(int i = 0; i < 8; ++i){
    if(bm & (1 << i)){
      if(pos[i] + p == l && col[i] == c){
        return pd;
      }
      else if(pos[i] + p - 1 == l && col[i] == c){
        bm ^= 1 << i;
      }
      else if(pos[i] + p >= 8){
        return pd;
      }
    }
  }

  if(!bm) return pd = 0;

  static int x[] = {-2,-2,-1,1,2,2,-1,1};
  static int y[] = {-1,1,2,2,-1,1,-2,-2};

  for(int i = 0; i < 8; ++i){
    pd = min(pd, 1 + f(l + x[i], c + y[i], p + 1, bm));
  }
  return pd;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int p;
  while(cin >> p && p){
    memset(memo, -1, sizeof memo);

    for(int i = 0, x; i < p; ++i){
      cin >> x;
      pos[i] = (x - 1) / 8;
      col[i] = (x - 1) % 8;
    }
    int h;
    cin >> h;

    int ans = f((h - 1) / 8, (h - 1) % 8, 0, (1 << p) - 1);
    if(ans == inf){
      cout << "impossible\n";
    }
    else{
      cout << ans << '\n';
    }
  }

  return 0;
}
