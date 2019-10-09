#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1003;

char code[maxn][maxn];
int dis[maxn][maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> code[i][j];
        dis[i][j] = inf;
      }
    }
    dis[0][0] = 0;
    deque<pair<int,int>> q;
    q.emplace_back(0, 0);
    while (!q.empty()) {
      int x, y;
      tie(x, y) = q.front();
      q.pop_front();
      for (int k = 0; k < 4; ++k) {
        static int X[] = {-1,1,0,0};
        static int Y[] = {0,0,-1,1};
        int xk = x + X[k];
        int yk = y + Y[k];
        if (0 <= xk && xk < n && 0 <= yk && yk < m) {
          int d = code[x][y] != code[xk][yk];
          if (dis[x][y] + d < dis[xk][yk]) {
            dis[xk][yk] = dis[x][y] + d;
            d == 0 ? q.emplace_front(xk, yk) : q.emplace_back(xk, yk);
          }
        }
      }
    }
    cout << "Case " << t << ": " << dis[n - 1][m - 1] << '\n';
  }
  return 0;
}
