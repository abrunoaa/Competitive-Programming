#include <bits/stdc++.h>
using namespace std;

const int maxn = 51;

int h, w;
char mat[maxn][maxn];
int memo[maxn][maxn][27];

int dfs(int i, int j, char c) {
  int &dp = memo[i][j][c - 'A'];
  if (dp != -1) return dp;
  dp = 0;
  for (int k = 0; k < 8; ++k) {
    static int I[] = {-1,-1,-1,0,0,1,1,1};
    static int J[] = {-1,0,1,-1,1,-1,0,1};
    int x = i + I[k];
    int y = j + J[k];
    if (0 <= x && x < h && 0 <= y && y < w && mat[x][y] == c) {
      dp = max(dp, dfs(x, y, (char)(c + 1)) + 1);
    }
  }
  return dp;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int cs = 0;
  while (cin >> h >> w && (h || w)) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> mat[i][j];
      }
    }
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (mat[i][j] == 'A') {
          ans = max(ans, 1 + dfs(i, j, 'B'));
        }
      }
    }
    cout << "Case " << ++cs << ": " << ans << '\n';
  }
  return 0;
}
