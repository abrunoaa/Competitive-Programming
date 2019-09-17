#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e4;

int r, k, ans;
bool use[maxn][maxn];
bool vis[maxn][maxn];
map<int,pair<int,int>> pos;

void build() {
  for (int i = 1, len = r, add = 1, cnt = 0; i <= 2 * r - 1; ++i, len += add) {
    for (int j = 1; j <= len; ++j) {
      pos[++cnt] = {i, j};
    }
    if (i == r) {
      add = -1;
    }
  }
}

void f(int i, int j) {
  if (i < 0 || i >= 2 * r + 1 || j < 0 || j >= 2 * r + 1) return;
  if (vis[i][j]) return;
  if (use[i][j]) {
    ++ans;
    return;
  }
  vis[i][j] = 1;
  f(i, j - 1);
  f(i, j + 1);
  f(i - 1, j - (i <= r));
  f(i - 1, j - (i <= r) + 1);
  f(i + 1, j - (i >= r));
  f(i + 1, j - (i >= r) + 1);
}

int main() {
  assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> r >> k;
  build();
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    auto p = pos[x];
    use[p.first][p.second] = 1;
  }
  f(0, 0);
  cout << ans << '\n';
  return 0;
}
