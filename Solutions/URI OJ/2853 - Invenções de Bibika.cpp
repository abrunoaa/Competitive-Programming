#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 1010

char mat[maxn][maxn];
int n, m, dis[maxn][maxn];

inline bool check(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] != '@';
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(dis, inf, sizeof dis);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '@') {
        dis[i][j] = 0;
        for (int d = 0; d < 4; ++d) {
          static int I[] = {0, 1, 0, -1}, J[] = {1, 0, -1, 0};
          for (int k = 1, i2, j2; i2 = i + I[d] * k, j2 = j + J[d] * k, check(i2, j2); ++k) {
            int &x = dis[i2][j2];
            x = min(x, k);
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans = max(ans, dis[i][j]);
      if (dis[i][j] == inf) {
        ans = -1;
        goto exit;
      }
    }
  }

exit:
  cout << ans << '\n';

  return 0;
}
