#include <bits/stdc++.h>
using namespace std;

int line[10][10], col[10][10], blk[10][10];
int mat[10][10];

inline int calcBlk(int i, int j){
  return 2 * (i >= 4) + (j >= 4);
}

bool f(int i, int j){
  if(j == 8) ++i, j = 0;
  if(i == 8) return 1;
  if(mat[i][j]) return f(i, j + 1);

  int b = calcBlk(i, j);
  for(int d = 1; d <= 8; ++d){
    if(line[i][d] < 1 && col[j][d] < 1 && blk[b][d] < 2){
      ++line[i][d];
      ++col[j][d];
      ++blk[b][d];
      if(f(i, j + 1)){
        mat[i][j] = d;
        return 1;
      }
      --line[i][d];
      --col[j][d];
      --blk[b][d];
    }
  }

  return 0;
}

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    memset(line, 0, sizeof line);
    memset(col, 0, sizeof col);
    memset(blk, 0, sizeof blk);

    bool ok = 1;
    for(int i = 0; i < 8; ++i){
      for(int j = 0; j < 8; ++j){
        int &d = mat[i][j];
        cin >> d;
        if(d){
          int b = calcBlk(i, j);

          ++line[i][d];
          ++col[j][d];
          ++blk[b][d];

          ok &= line[i][d] <= 1 && col[j][d] <= 1 && blk[b][d] <= 2;
        }
      }
    }

    cout << "Test case #" << t << ": ";
    if(!ok || !f(0, 0)){
      cout << "NO\n";
    }
    else{
      cout << "YES\n";
      for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
          if(j) cout << ' ';
          cout << mat[i][j];
        }
        cout << '\n';
      }
    }
  }

  return 0;
}
