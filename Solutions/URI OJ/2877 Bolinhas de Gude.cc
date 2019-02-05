#include <bits/stdc++.h>
using namespace std;

#define maxn 110

int see[3 * maxn], mat[maxn][maxn];

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  for(int i = 1; i < maxn; ++i){
    for(int j = 1; j < maxn; ++j){
      if(i != j){
        if(min(i, j) == 1 && max(i, j) == 2){
          mat[i][j] = 0;
        }
        else{
          memset(see, 0, sizeof see);
          for(int k = 1; i - k > 0; ++k){
            if(i - k != j){
              see[mat[i - k][j]] = 1;
            }
          }
          for(int k = 1; j - k > 0; ++k){
            if(i != j - k){
              see[mat[i][j - k]] = 1;
            }
          }
          for(int k = 1; i - k > 0 && j - k > 0; ++k){
            see[mat[i - k][j - k]] = 1;
          }

          for(int k = 0; ; ++k){
            if(!see[k]){
              mat[i][j] = k;
              break;
            }
          }
        }
      }
    }
  }

  int n;
  cin >> n;

  int x = 0;
  while(n--){
    int l, c;
    cin >> l >> c;
    if(l == c){
      cout << "Y\n";
      return 0;
    }
    x ^= mat[l][c];
  }

  cout << (x ? 'Y' : 'N') << '\n';
  return 0;
}
