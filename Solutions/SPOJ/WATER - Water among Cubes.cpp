#include <bits/stdc++.h>
using namespace std;

struct tri {
  int h, x, y;
  bool operator > (const tri& t) const {
    return h > t.h;
  }
};

const int maxn = 103;

int a[maxn][maxn], b[maxn][maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    priority_queue<tri,vector<tri>,greater<tri>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
          q.push({a[i][j], i, j});
          b[i][j] = a[i][j];
        } else {
          b[i][j] = (int)1e9;
        }
      }
    }
    while (!q.empty()) {
      auto [h, i, j] = q.top();
      q.pop();
      if (h > b[i][j]) continue;
      for (int k = 0; k < 4; ++k) {
        static int di[] = {-1,1,0,0};
        static int dj[] = {0,0,-1,1};
        int x = i + di[k];
        int y = j + dj[k];
        if (0 <= x && x < n && 0 <= y && y < m && b[i][j] < b[x][y] && b[x][y] > a[x][y]) {
          b[x][y] = max(a[x][y], b[i][j]);
          q.push({b[x][y], x, y});
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans += b[i][j] - a[i][j];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
