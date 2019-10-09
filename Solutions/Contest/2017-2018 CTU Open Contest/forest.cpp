#include <bits/stdc++.h>
using namespace std;

const int maxm = 103;

int n, m;
char ans[maxm][maxm];

inline void change(int x, int y, char c) {
  if (0 <= x && x < m && 0 <= y && y < m) {
    ans[y][x] = c;
  }
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (cin >> m >> n) {
    memset(ans, '.', sizeof(ans));
    while (n--) {
      int s, x, y;
      cin >> s >> x >> y;
      if (s == 0) {
        change(x - 1, y, '_');
        change(x, y, 'o');
        change(x + 1, y, '_');
      } else {
        change(x - 1, y, '_');
        change(x, y, '|');
        change(x + 1, y, '_');
        for (int i = 1; i <= s; ++i) {
          change(x - 1, y + i, '/');
          change(x, y + i, '|');
          change(x + 1, y + i, '\\');
        }
        change(x, y + s + 1, '^');
      }
    }
    cout << string(m + 2, '*') << '\n';
    for (int i = m - 1; i >= 0; --i) {
      ans[i][m] = '\0';
      cout << '*' << ans[i] << "*\n";
    }
    cout << string(m + 2, '*') << "\n\n";
  }
  return 0;
}
