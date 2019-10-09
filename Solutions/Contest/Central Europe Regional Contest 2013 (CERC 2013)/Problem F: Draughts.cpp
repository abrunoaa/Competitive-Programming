#include <bits/stdc++.h>
using namespace std;

char mat[13][13];

int f(int i, int j) {
  static int I[] = {-1,-1,1,1};
  static int J[] = {-1,1,-1,1};
  int ans = 0;
  for (int k = 0; k < 4; ++k) {
    int a = i + I[k];
    int b = j + J[k];
    int x = i + 2 * I[k];
    int y = j + 2 * J[k];
    if (0 <= x && x < 10 && 0 <= y && y < 10 && mat[a][b] == 'B' && mat[x][y] == '#') {
      mat[a][b] = '#';
      ans = max(ans, f(x, y) + 1);
      mat[a][b] = 'B';
    }
  }
  return ans;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        cin >> mat[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (mat[i][j] == 'W') {
          mat[i][j] = '#';
          ans = max(ans, f(i, j));
          mat[i][j] = 'W';
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
