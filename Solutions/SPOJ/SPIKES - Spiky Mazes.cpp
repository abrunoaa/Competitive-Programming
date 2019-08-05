#include <bits/stdc++.h>
using namespace std;

#define maxn 50

int n, m;
char s[maxn][maxn];
bool vis[maxn][maxn];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != '#';
}

bool f(int i, int j, int n) {
  if (!valid(i, j) || vis[i][j]) { return 0; }
  if (s[i][j] == 'x') { return 1; }

  vis[i][j] = 1;
  n -= s[i][j] == 's';
  if (n < 0) { return 0; }

  for (int k = 0; k < 4; ++k) {
    static const int I[] = {-1, 1, 0, 0}, J[] = {0, 0, -1, 1};
    if (f(i + I[k], j + J[k], n)) {
      return 1;
    }
  }
  vis[i][j] = 0;
  return 0;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '@' && f(i, j, k / 2)) {
        cout << "SUCCESS\n";
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
