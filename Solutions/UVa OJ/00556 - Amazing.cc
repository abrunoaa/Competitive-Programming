#include <bits/stdc++.h>
using namespace std;

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int b, w;
  vector<string> mat;
  vector<vector<int>> vis;
  while(cin >> b >> w, b || w){
    mat.assign(b + 2, string(w + 2, 1));
    vis.assign(b + 2, vector<int>(w + 2, 0));

    int ans[5] = {};
    for(int i = 1; i <= b; ++i){
      for(int j = 1; j <= w; ++j){
        cin >> mat[i][j];
        mat[i][j] -= '0';
        ans[0] += !mat[i][j];
      }
    }

    // dir:
    //    3
    //  2   0
    //    1
    int dir = 0;
    int i = b, j = 1;

    static int I[] = {0,+1,0,-1}, J[] = {+1,0,-1,0};

    bool flag = 1, turnRight = 0;
    while(i != b || j != 1 || flag){

      int f = mat[i + I[dir]][j + J[dir]];
      int r = (dir + 1) % 4;
      r = mat[i + I[r]][j + J[r]];

      if(!r && !turnRight){
        dir = (dir + 1) % 4;
        turnRight = 1;
      }
      else{
        turnRight = 0;

        if(f){
          dir = (dir - 1 + 4) % 4;
        }
        else{
          flag = 0;

          int &v = vis[i][j];
          if(v <= 4){
            --ans[v];
            ++v;
            if(v <= 4){
              ++ans[v];
            }
          }

          i += I[dir];
          j += J[dir];
        }
      }
    }

    for(int i = 0; i <= 4; ++i){
      cout << setw(3) << ans[i];
    }
    cout << '\n';
  }

  return 0;
}
